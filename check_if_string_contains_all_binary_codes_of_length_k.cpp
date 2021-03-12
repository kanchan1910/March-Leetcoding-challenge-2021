class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        int total_number_of_codes = pow(2, k);
        unordered_set<string>ss;
        for(int i = 0 ; i <= s.length() - k; i++)
        {
            ss.insert(s.substr(i, k));
        }
     return ss.size() == total_number_of_codes ? true : false;
        
    }
};

// tc o(n - k)
// sc o(n)
