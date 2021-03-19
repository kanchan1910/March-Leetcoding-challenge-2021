class Solution {
public:
    void dfs(int source,int n, vector<bool>&vis, vector<vector<int>>&rooms)
    {
        vis[source] = true;
        for(auto child : rooms[source])
        {
            if(vis[child] == false)
            {
                dfs(child, n , vis , rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n = rooms.size();

        vector<bool>vis(n , false);
        dfs(0, n,vis,rooms);
        for(int i = 0 ; i < n ;i++)
        {
            if(vis[i] == false)
            {
                return false;
            }
        }
        return true;
        
    }
};
