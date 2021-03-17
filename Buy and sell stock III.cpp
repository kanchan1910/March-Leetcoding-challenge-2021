class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int firstbuy = INT_MIN;
        int firstsell = 0;
        int secondbuy  = INT_MIN;
        int secondsell = 0;
        int n = prices.size();
        for(int i = 0 ; i < n  ; i++)
        {
            firstbuy = max(firstbuy , -prices[i]);
            firstsell = max(firstsell , firstbuy + prices[i]);
            secondbuy = max(secondbuy , firstsell - prices[i]);
            secondsell = max(secondsell , secondbuy + prices[i]);
        }
        return secondsell;
    }
};
// tc O(N)
// sc O(1)
