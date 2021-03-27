// method 1 (fails due to my wrong logic)

class Solution {
public:
    // fails on case aba
    int countSubstrings(string s)
    {
        int ans = 1;
        int n = s.length();
        for(int i = 1; i < n ; i++)
        {
            if(s[i] != s[i - 1])
            {
                ans++;
            }
            else
            {
                ans = max(ans , ((i + 1) * (i + 2)) / 2);
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(1)

// method 2 (accepted)

class Solution {
public:
    // brute force
    bool fun(string s)
    {
        int n = s.length();
       for(int i = 0 ; i < n / 2; i++)
       {
           if(s[i] != s[n - i - 1])
           {
               return false;
           }
       }
        return true;
    }
    int countSubstrings(string s)
    {
       int n = s.length();
       int ans = 0;
       
       for(int i = 0 ; i < n; i++)
       {
           for(int j = i ; j < n; j++)
           {
               if(fun(s.substr(i , j - i + 1)) == true)
               {
                   ans++;
               }
           }
       }
       return ans;
    }
};
// tc o(n^3)
// sc o(1)

// method 3 (accepted)

class Solution {
public:
    // memoization
    int dp[1005][1005]; // for storing starting index and the ending index
    int fun(string s, int i , int j)
    {
        if(i >= j)
        {
            return 1;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(s[i] == s[j])
        {
             dp[i][j] = fun(s, i + 1 , j - 1);
        }
        else
        {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }
    int countSubstrings(string s)
    {
       int n = s.length();
       int ans = 0;
       memset(dp, -1, sizeof(dp));
     
       for(int i = 0 ; i < n; i++)
       {
           for(int j = i ; j < n; j++)
           {
               if(fun(s, i, j) == 1)
               {
                   ans++;
               }
           }
       }
       return ans;
    }
};
// tc o(n^2)
// sc O(n^2)

// method 4 (accepted)

class Solution {
public:
    // tabulation method
    int countSubstrings(string s)
    {
       int n = s.length();
       int ans = n;
       bool dp[1005][1005] = {false};
       // for length 1
       for(int i = 0 ; i < n; i++)
       {
           dp[i][i] = true;
       }
        // for length 2
       for(int i = 0 ; i < n - 1; i++)
       {
           if(s[i] == s[i + 1])
           {
               dp[i][i + 1] = true;
               ans++;
           }
       }
        // from length 3 to n
        for(int len = 3 ; len <= n ; len++)
        {
            for(int start = 0 ; start + len - 1 < n; start++)
            {
                int end = start + len - 1;
                if(s[start] == s[end] && dp[start + 1][end - 1] == true)
                {
                    dp[start][end] = true;
                    ans++;
                }
            }
        }
       return ans;
    }
};
// tc o(n^2)
// sc O(n^2)

// method 5  (accepted)(most tricky method)

class Solution {
public:
    // two pointer approach
    int fun(string s, int l , int r)
    {
        int cur = 0;
        int n = s.length();
        while(l >= 0 && r < n && s[l] == s[r])
        {
            cur++;
            l--;
            r++;
        }
        return cur;
    }
    int countSubstrings(string s)
    {
       int n = s.length();
       int ans = 0;
       for(int i = 0 ; i < n ; i++)
       {
           ans += fun(s, i , i); // for odd length
           ans += fun(s, i , i + 1); // for even length
       }
       return ans;
    }
};
// tc o(n^2)
// sc O(1)
