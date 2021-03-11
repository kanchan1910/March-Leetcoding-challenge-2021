class Solution {
public:
    int fun(char ch)
    {
        if(ch == 'I')
        {
            return 1;
        }
        if(ch == 'V')
        {
            return 5;
        }
        if(ch == 'X')
        {
            return 10;
        }
        if(ch == 'L')
        {
            return 50;
        }
        if(ch == 'C')
        {
            return 100;
        }
        if(ch == 'D')
        {
            return 500;
        }
        if(ch == 'M')
        {
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(i == n - 1)
            {
                ans += fun(s[i]);
            }
            else
            {
            int num1 = fun(s[i]);
            int num2 = fun(s[i + 1]);
            if(num1 < num2)
            {
                ans += num2 - num1;
                i++;
            }
            else
            {
                ans += num1;
            }
                
            }
        }
        return ans;
    }
};
