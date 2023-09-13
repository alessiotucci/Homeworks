public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        int count = 0;
        int joy;
        int[] solution = new int[2];
        while (count < nums.Length)
        {
            joy = count + 1;
            while (joy < nums.Length)
            {
            if (target == nums[count] + nums[joy]) 
                return new int[2]{count, joy};
            joy++;
            }
            count++;
        }
        return new int[2];

    }
}
