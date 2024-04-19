/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:04:30 by atucci            #+#    #+#             */
/*   Updated: 2024/04/19 13:03:44 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int write_error(char *message)
{
	int count = 0;
	while (message[count])
	{
		write(2, &message[count], 1);
		count++;
	}
	return 1;
}

int my_cd(char **commands, int i)
{
	if (i != 2)
		return (write_error("error: cd: bad arguments\n"));
	else if (chdir(commands[1]) == -1)
	{
		write_error("error: cd: cannot change directory to ");
		write_error(commands[1]);
		return (write_error("\n"));
	}
	return 0;
}

int my_exec(char **commands, char **envp, int i)
{
	int fd[2];
	int status;
	int has_pipe = commands[i] && strcmp(commands[i], "|") == 0;
	if (has_pipe && pipe(fd) == -1)
		return (write_error("error: fatal\n"));
	
	int pid = fork();
	if (pid == 0)
	{
		commands[i] = NULL; // put the null terminated here
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1
											  || close(fd[1]) == -1))
		return (write_error("error: fatal\n"));
		execve(commands[0], commands, envp);
		write_error("error: cannot execute ");
		write_error(commands[0]);
		return write_error("\n");
	}
	waitpid(pid, &status, 0);
	// check for closing the fd
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1
										  || close(fd[1]) == -1))
		return (write_error("error: fatal\n"));
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int ac, char **av, char **env)
{
	int i = 0; // iterator
	int exit_status;

	if (ac > 1)
	{
		// setting up the while cycle
		while (av[i] && av[++i]) // pre increment cmon
		{
			//first increment av, then  reset the counter
			av += i;
			i = 0;
			// second while cycle
			while (av[i] && strcmp(av[i], "|")
								  && strcmp(av[i], ";"))
				i++;
			//Now we can start executing
			if (strcmp(av[0], "cd") == 0) // == 0 means are equals
				exit_status = my_cd(av, i);
			else if (i)
				exit_status = my_exec(av, env, i);
		}
	}
	return (exit_status);
}
