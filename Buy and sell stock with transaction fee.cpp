class Solution {
public:
    int dp[50005][2];
    int fun(vector<int>&prices, int i , int n , int buy, int fee)
    {
        if(i >= n)
        {
            return 0;
        }
        if(dp[i][buy] != -1)
        {
            return dp[i][buy];
        }
        if(buy == 0)
        {
            dp[i][buy] = max(fun(prices , i + 1 , n , 0 , fee) , fun(prices , i + 1 , n, 1 , fee)- prices[i]);
        }
        else if(buy == 1)
        {
            dp[i][buy] = max(fun(prices , i + 1 , n , 1 , fee) , fun(prices , i + 1, n , 0 , fee) - fee + prices[i]);
        }
        return dp[i][buy];
    }
        
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        if(n < 2)
        {
            return 0;
        }
        memset(dp , -1 , sizeof dp);
        return fun(prices , 0 , n , 0 , fee);
        
    }
};
