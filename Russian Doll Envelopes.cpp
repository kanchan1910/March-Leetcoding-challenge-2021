class Solution {
public:
    static bool com(vector<int>&a,vector<int>&b)
    {
        if(a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), com);
        vector<int>dp(n , 1);
        for(int i = 1; i < n ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                {
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// variation of classic LIS problem 
// tc o(n * n)
// sc o(n)

/* Greedy will not work here , as we can see the example [[5,5],[6,4],[6,7],[4,3],[1,3],[2,4]] , according to greedy answer would be 3 ,instead the ans is 4 */
