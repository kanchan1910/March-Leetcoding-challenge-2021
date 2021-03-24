class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0 ; i <= n - 3; i++)
        {
            int l = i + 1;
            int r = n - 1;
            while(l < r)
            {
                int sum = arr[i] + arr[l] + arr[r];
                if(sum == target)
                {
                    bool equal = false;
                    if(arr[l] == arr[r])
                    {
                        equal = true;
                    }
                    int countl = 1 , countr = 1;
                    while(l + 1 < r && arr[l] == arr[l + 1])
                    {
                        l++;
                        countl++;
                    }
                    while(r - 1 > l && arr[r] == arr[r - 1])
                    {
                        r--;
                        countr++;
                    }
                    l++;
                    r--;
                    if(equal == true)
                    {
                        ans = (ans + countl * (countl + 1)/2) % 1000000007;
                    }
                    else
                    {
                        ans = (ans + countl * countr) % 1000000007;
                    }
                   
                }
                else if(sum < target)
                {
                    l++;
                }
                else if(sum > target)
                {
                    r--;
                }
            }
        }
        return ans;
    }
};
