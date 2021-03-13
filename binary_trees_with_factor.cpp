class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        unordered_map<int,long long>m;
        int n = arr.size();
        int ans = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0 ; i < n ; i++)
        {
            m[arr[i]] = 1;
            for(int j = 0 ; j < i ; j++)
            {
                if(arr[i] % arr[j] == 0)
                {
                    m[arr[i]] = (m[arr[i]]  + (m[arr[j]] * m[arr[i] / arr[j]]) % 1000000007) % 1000000007;

                }
            }
            //                    cout << m[arr[i]] << " ";
            ans = (ans + m[arr[i]] ) % 1000000007;
        }
        return ans;
    }
};
// sc o(n)
// tc o(n * n)
