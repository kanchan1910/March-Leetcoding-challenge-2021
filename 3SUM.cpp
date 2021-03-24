class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        if(n < 3)
        {
            return {};
        }
        for(int i = 0 ; i <= n - 3; i++)
        {
            int l = i + 1;
            int r = n - 1;
            while(l < r)
            {
            if(nums[i] + nums[l] + nums[r] == 0)
            {
               vector<int>tmp({nums[i] , nums[l], nums[r]});
                s.insert(tmp);
                l++;
                r--;
            }
            else if(nums[i] + nums[l] + nums[r] < 0)
            {
                l++;
            }
            else if(nums[i] + nums[l] + nums[r] > 0)
            {
                r--;
            }
            }
        }
        vector<vector<int>>ans(s.begin() , s.end());
        return ans;
    }
};
// tc o(n*n)
// sc o(1)
