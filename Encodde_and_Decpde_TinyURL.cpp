class Solution {
public:
int count = 0;
    unordered_map<string,string>m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string shortUrl = "http://tinyurl.com/4" + to_string(count);
        count++;
        m.insert({shortUrl , longUrl});
        
     return shortUrl;   
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        return m[shortUrl];
        
    }
};
// tc o(1)
// sc o(n)
