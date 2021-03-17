class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int profit = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                if(prices[j] > prices[i])
                {
                     profit = max(profit , prices[j] - prices[i]);
                }
            }
        }
        return profit;
    }
};
//tle
// tc o(n * n)
// sc o(1)



class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int profit = 0;
        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {
            mini  = min(mini , prices[i]);
            profit = max(profit , prices[i] - mini);
        }
        return profit;
    }
};
// accepted 
// tc o(n)
// sc o(1)
