class Solution {
public:
    int parent[100005];
    int rnk[100005];
    int findpar(int par)
    {
        if(parent[par]==par)
            return par;
        return parent[par]=findpar(parent[par]);
    }
    bool uni(int u,int v)
    {
        u=findpar(u);
        v=findpar(v);
        if(u==v)
            return false;
        else
        {
            if(rnk[u]>rnk[v])
                parent[v]=u;
            else
            if(rnk[u]<rnk[v])
                parent[u]=v;
            else
            if(rnk[u]==rnk[v])
            {
                rnk[u]+=1;
                parent[v]=u;
            }
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& ed) {
        vector<int> vc;
        for(int i=0;i<100005;i++){
            rnk[i]=0;
            parent[i]=i;
        }
        for(int i=0;i<ed.size();i++)
        {
            if(uni(ed[i][0],ed[i][1])==false){
                vc.push_back(ed[i][0]);
                vc.push_back(ed[i][1]);
            }
        }
        return vc;
    }
};
