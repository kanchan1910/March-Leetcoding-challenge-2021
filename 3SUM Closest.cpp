class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int ans;
        for(int i = 0 ; i <= n - 3 ; i++)
        {
            int l = i + 1;
            int r = n - 1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target)
                {
                   return target;
                }
                else if(sum < target)
                {
                    l++;
                    if(target - sum < diff)
                    {
                        diff = target - sum;
                        ans = sum;
                    }
                }
                else if(sum > target)
                {
                    r--;
                    if(sum - target < diff)
                    {
                        diff = sum - target;
                        ans = sum;
                    }
                }
            }
            
        }
        return ans;
    }
};
// tc o(n*n)
// sc (1)
