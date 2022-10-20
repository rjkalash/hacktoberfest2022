class Solution{
public:
bool fn=false;
    void path(int node,int n,vector<int> &vis,vector<int> adj[])
    {
        if(vis[node]==1)
            return;
        vis[node]=1;
        int sum=accumulate(vis.begin(),vis.end(),0);
        if(sum==n+1)
            fn=true;
        for(auto it:adj[node])
        {
            path(it,n,vis,adj);
        }
        vis[node]=0;
    }
    bool check(int n,int M,vector<vector<int>> ed)
    {
        vector<int> adj[n+1];
        for(int i=0;i<M;i++)
        {
            adj[ed[i][0]].push_back(ed[i][1]);
            adj[ed[i][1]].push_back(ed[i][0]);
        }
        vector<int> vis(n+1,0);
        vis[0]=1;
        for(int i=1;i<=n;i++)
            path(i,n,vis,adj);
        return fn;
    }
};
