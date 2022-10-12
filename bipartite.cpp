class Solution {
public:
    //using dfs
    bool dfs(vector<vector<int>> &arr,int node,vector<int> &vis)
    {
        if(vis[node]==-1)
            vis[node]=1;
        for(auto i:arr[node])
        {
            if(vis[i]==-1)
            {
                vis[i]=1-vis[node];
                if(!dfs(arr,i,vis))
                    return false;
            }
            else
            if(vis[i]==vis[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);
        
        for(int i=0;i<graph.size();i++)
        {
            if(vis[i]==-1)
            {
                if(!dfs(graph,i,vis))
                    return false;
            }
        }
        return true;
    }
};
