class Solution {
public:
    int distributeCandies(vector<int>& candyType)
    {
        int n = candyType.size();
        unordered_set<int>s;
        for(int i = 0 ; i < n ; i++)
        {
            s.insert(candyType[i]);
        }
        return min(s.size(), candyType.size()/2);
    }
};
// tc o(n)
// sc o(n)




class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
      sort(candyType.begin(), candyType.end());
        int candies = 1; // number of unique candies
        for(int i = 1; i < candyType.size(); i++)
        {
            if(candyType[i] != candyType[i - 1])
            {
                candies++;
            }
        }
        if(candies < candyType.size()/2)
        {
            return candies;
        }
        return candyType.size()/2;
    }
};

// tc o(nlogn)
// sc o(1)
