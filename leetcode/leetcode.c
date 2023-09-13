#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced,
assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
// that nums in the arrays of ints
// numsSize is useful to create the loops
int result;
int count;
int joy;
// this is the alllocation of memory
int *solution = malloc(sizeof(int) * 2);

// nested while loops
count = 0;
while (count < numsSize - 1) // this is out condition 
{
joy = count + 1;
	while (joy < numsSize) // this is the inner loop condition
	{
	result = nums[count] + nums[joy];
	if (result == target) // this is out IF condition
		{
		solution[0] = count;
		solution[1] = joy;
		*returnSize = 2;
		return (solution);
		}
	joy++;
	}
count++;
}
// Let's say there is no anwer
	free(solution); // free only if there is no answer
	*returnSize = 0;
	return NULL;
}




int main() 
{
  int nums1[] = {2, 7, 11, 15};
  int target1 = 9;
  int returnSize1;
  int* solution1 = twoSum(nums1, sizeof(nums1)/sizeof(nums1[0]), target1, &returnSize1);
  if (solution1 != NULL) {
    printf("\033[0;32mFound solution 1: nums[a] = %d, nums[b] = %d\033[0m\n", solution1[0], solution1[1]);
    free(solution1);
  } else {
    printf("\033[0;31mNo solution found for target 1\033[0m\n");
  }

  int nums2[] = {3, 2, 4};
  int target2 = 6;
  int returnSize2;
  int* solution2 = twoSum(nums2, sizeof(nums2)/sizeof(nums2[0]), target2, &returnSize2);
  if (solution2 != NULL) {
    printf("\033[0;32mFound solution 2: nums[a] = %d, nums[b] = %d\033[0m\n", solution2[0], solution2[1]);
    free(solution2);
  } else {
    printf("\033[0;31mNo solution found for target 2\033[0m\n");
  }

  return 0;
}
































