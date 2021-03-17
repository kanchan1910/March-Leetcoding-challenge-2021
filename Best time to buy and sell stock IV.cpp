class Solution {
public:
    int dp[1002][102][2];
    int fun(vector<int>&prices , int n , int k , int i , int buy)
    {
        if(i >= n || k == 0)
        {
            return 0;
        }
        if(dp[i][k][buy] != -1)
        {
            return dp[i][k][buy];
        }
        // two cases :
        /*
        if(buy == 0) , means we can either skip or can buy
        else if buy == 1 , means we can either skip or can sell
        */
        /*
        buy = 0 means till now we have not bought and so we can buy
        this wordks as a flag variable which helps us to avoid overlapping transactions
        */
        if(buy == 0)
        {
            dp[i][k][buy] = max(fun(prices , n, k , i + 1 , 0) , fun(prices, n , k , i + 1, 1) - prices[i]);
        }
        else if(buy == 1)
        {
            dp[i][k][buy] = max(fun(prices, n , k, i + 1 , 1) , fun(prices, n, k - 1 , i + 1,0) + prices[i]);
        }
        return dp[i][k][buy];
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        memset(dp , -1 , sizeof(dp));
        return fun(prices, n, k , 0, 0);
    }
};
