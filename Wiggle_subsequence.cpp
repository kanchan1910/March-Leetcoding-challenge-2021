class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        // Greedy approach
        int ans = 1;
        int prev_sign = 0;
        int n = nums.size();
        for(int i = 1 ; i < n ; i++)
        {
            int cur_sign = nums[i] - nums[i - 1];
            if(cur_sign < 0 && prev_sign >= 0 || cur_sign > 0 && prev_sign <= 0)
            {
                ans++;
                prev_sign = cur_sign;
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(1)


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        // DP approach
        int n = nums.size();
        vector<int>up(n),down(n);
        down[0] = 1, up[0] = 1;
        for(int i = 1; i < n ; i++)
        {
            if(nums[i] > nums[i - 1])
            {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            }
            else if(nums[i] < nums[i - 1])
            {
                up[i] = up[i - 1];
                down[i] = up[i - 1] + 1;
            }
            else if(nums[i] == nums[i - 1])
            {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(down[n - 1] , up[n - 1]);
    }
};
  /** up[i] is the length of a longest wiggle subsequence of {nums[0],...,nums[i]}, with a
            positive difference between its last two numbers. This subsequence may or may not
            include nums[i] and there may be several such subsequences (of the same length).            
         */

            /** down[i] is the length of a longest wiggle subsequence of {nums[0],...,nums[i]}, with a
            negative difference between its last two numbers. This subsequence may or may not
            include nums[i] and there may be several such subsequences (of the same length).            
         */
// tc o(n)
// sc o(n)