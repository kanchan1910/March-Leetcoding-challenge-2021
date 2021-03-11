class Solution {
public:
    int fun(vector<int>&coins, int amount , vector<vector<int>>&dp,int index)
    {
        if(amount < 0 || index >= coins.size())
        {
            return 100005;
        }
        if(amount == 0)
        {
            return 0;
        }
        if(dp[index][amount] != -1)
        {
            return dp[index][amount];
        }
        if(coins[index] > amount)
        {
            dp[index][amount] = fun(coins, amount , dp , index + 1);
        }
        else if(coins[index] <= amount)
        {
             dp[index][amount] = min(fun(coins , amount , dp, index + 1), 1 + fun(coins , amount - coins[index] , dp, index));
        }
        return dp[index][amount];
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
    vector<vector<int>>dp(n + 1, vector<int>(amount + 1, -1));
        int ans = fun(coins, amount , dp, 0);
       
        if(ans == 100005)
        {
            return -1;
        }
        return ans;
    }
};
