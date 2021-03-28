class Solution {
public:
    string originalDigits(string s) 
    {
        string ans = "";
        int freq[26] = {0};
        for(int i = 0 ; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }
        int count[10] = {0};
        count[0] = freq['z' - 'a'];
        count[2] = freq['w' - 'a'];
        count[6] = freq['x' - 'a'];
        count[8] = freq['g' - 'a'];
        count[4] = freq['u' - 'a'];
        count[5] = freq['f' - 'a'] - count[4];
        count[7] = freq['s' - 'a'] - count[6];
        count[3] = freq['h' - 'a'] - count[8];
        count[1] = freq['o' - 'a'] - count[0] - count[2] - count[4];
        count[9] = freq['i' - 'a'] - count[5] - count[6] - count[8];
        for(int i = 0 ; i < 10 ; i++)
        {
            if(count[i] > 0)
            {
             while(count[i]--)
            {
                ans += i + '0';
            }   
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(n)
