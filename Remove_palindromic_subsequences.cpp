class Solution {
public:
    bool isPalindrome(string str)
    {
        int l = 0 , r = str.length() - 1;
        while(l < r)
        {
            if(str[l] != str[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int removePalindromeSub(string s) 
    {
        if(s == "")
        {
            return 0;
        }
        if(isPalindrome(s) == true)
        {
            return 1;
        }
        return 2;
    }
};
// tc o(n)
// sc o(1)


// main fact of question "string consists of only 2 characters"
