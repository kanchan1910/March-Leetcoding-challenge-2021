class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) 
    {
        multiset<int>s;
        vector<int>ans;
        for(int i = 0 ; i < A.size() ; i++)
        {
            s.insert(A[i]);
        }
        for(int i = 0 ; i < B.size(); i++)
        {
            auto itr = s.upper_bound(B[i]);
            if(itr == s.end())
            {
                ans.push_back(*(s.begin()));
                s.erase(s.begin());
            }
            else
            {
                ans.push_back(*itr);
                s.erase(itr);
            }
        }
        return ans;
    }
};
// tc o(nlogn)
// sc o(n)
