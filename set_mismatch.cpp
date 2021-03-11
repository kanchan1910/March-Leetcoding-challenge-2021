class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        vector<int>ans(2);
        int ss = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(s.find(nums[i]) == s.end())
            {
                s.insert(nums[i]);
                ss += nums[i];
            }
            else
            {
                ans[0] =  nums[i];
            }
        }
        int sum = (n * (n + 1)) / 2;
        ans[1] = sum - ss;
        return ans;
    }
};
// tc o(n)
// sc o(n)


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(2);
        for(int i = 0 ; i < n ;)
        {
            if(nums[i] == i + 1)
            {
                i++;
            }
            else
            {
                if(nums[i] != nums[nums[i] - 1])
                {
                    swap(nums[i], nums[nums[i] - 1]);
                }
                else
                {
                    i++;
                }
                
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == i + 1)
            {
                continue;
            }
            else
            {
                ans[0] = nums[i];
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(1)
