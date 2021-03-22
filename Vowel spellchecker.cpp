class Solution {
public:
    string fun(string str)
    {
        for(int i = 0 ; i < str.length(); i++)
        {
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            {
                str[i] = '*';
            }
        }
        return str;
    }
    string tolowerfun(string str)
    {
        for(int i = 0 ; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }
        return str;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries)
    {
        unordered_set<string>list;
        unordered_map<string , string >c , v;
        vector<string>ans;
        for(int i = 0 ; i < wordlist.size(); i++)
        {
            list.insert(wordlist[i]);
            if(c.find(tolowerfun(wordlist[i])) == c.end())

            {
                c[tolowerfun(wordlist[i])] = wordlist[i];
            }
            if(v.find(fun(tolowerfun(wordlist[i]))) == v.end())
            {
                v[fun(tolowerfun(wordlist[i]))] = wordlist[i];
            }
        }
        for(int i = 0 ; i < queries.size() ; i++)
        {
            if(list.find(queries[i]) != list.end())
            {
                ans.push_back(queries[i]);
            }
            else if(c.find(tolowerfun(queries[i])) != c.end())
            {
                ans.push_back(c[tolowerfun(queries[i])]);
            }
            else if(v.find(fun(tolowerfun(queries[i]))) != v.end())
            {
                ans.push_back(v[fun(tolowerfun(queries[i]))]);
            }
            else
            {
                ans.push_back("");
            }
        }
        return ans;
    }
};
