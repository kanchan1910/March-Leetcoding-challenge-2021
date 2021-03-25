class Solution {
public:
    void fun(int n , int m , queue<pair<int , int>>&q, vector<vector<int>>&matrix, vector<vector<bool>>&vis)
    {
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x + 1 < n && vis[x + 1][y] == false && matrix[x][y] <= matrix[x + 1][y])
            {
                q.push({x + 1, y});
                vis[x + 1][y] = true;
            }
            if(x - 1 >= 0 && vis[x - 1][y] == false && matrix[x][y] <= matrix[x - 1][y])
            {
                q.push({x - 1, y});
                vis[x - 1][y] = true;
            }
            if(y - 1 >= 0 && vis[x][y - 1] == false && matrix[x][y] <= matrix[x][y - 1])
            {
                q.push({x , y - 1});
                vis[x][y - 1] = true;
            }
            if(y + 1 < m && vis[x][y + 1] == false && matrix[x][y] <= matrix[x][y + 1])
            {
                q.push({x, y + 1});
                vis[x][y + 1] = true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
    {
        vector<vector<int>>ans;
        int n = matrix.size();
        if(n == 0)
        {
            return ans;
        }
        int m = matrix[0].size();
        if(m == 0)
        {
            return ans;
        }
        vector<vector<bool>>pacific(n, vector<bool>(m , false));
        vector<vector<bool>>atlantic(n , vector<bool>(m , false));
        queue<pair<int , int>>q;
        
        // for pacific ocean
        for(int i = 0 ; i < n ; i++)
        {
            q.push({i , 0});
            pacific[i][0] = true;
        }
        for(int i = 0 ; i < m ; i++)
        {
            q.push({0 , i});
            pacific[0][i] = true;
        }
        // will tell which cells can reach pacific ocean
         fun(n , m , q, matrix , pacific);
        
        // for atlantic ocean
        for(int i = 0 ; i < n ; i++)
        {
            q.push({i , m - 1});
            atlantic[i][m - 1] = true;
        }
        for(int i = 0 ; i < m ; i++)
        {
            q.push({n - 1 , i});
            atlantic[n - 1][i] = true;
        }
        // will tell which cells can reach atlantic ocean
        fun(n , m , q, matrix , atlantic);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(pacific[i][j] == true && atlantic[i][j] == true)
                {
                    // will then the cells which can reach both atlantic and pacific ocean
                    ans.push_back({i , j});
                }
            }
        }
        return ans;
    }
};
// tc o(n * m)
// sc o(n * m)
