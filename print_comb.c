#include <unistd.h>

 void ft_helper(int a, int b, int c) {
     if (a == 10) return;
    else if (b == 10) ft_helper(a + 1, a + 2, a + 3);
   else if (c == 10) ft_helper(a, b + 1, b + 2);
     else {
        write(1, ", ", 2);
         write(1, "0123456789" + a, 1);
         write(1, "0123456789" + b, 1);
        write(1, "0123456789" + c, 1);
				/* 12 */         ft_helper(a, b, c + 1);
				/* 13 */     }
			/* 14 */ }
			/* 15 */
			/* 16 */ void ft_print_comb(void) {
				/* 17 */     write(1, "012", 3);
				/* 18 */     ft_helper(0, 1, 3);
				/* 19 */     write(1, "\n", 1);
				/* 20 */ }
				/* 21 */
				/* 22 */ int main(void) {
					/* 23 */     ft_print_comb();
					/* 24 */     return 0;
					/* 25 */ }
