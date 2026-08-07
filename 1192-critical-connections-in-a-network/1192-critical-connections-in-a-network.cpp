class Solution {

    void dfs(int u ,int parent,vector<vector<int>>& adj,vector<int>&tin,vector<int>&low,vector<bool>&visited,int& timer,vector<vector<int>>&bridges){
        visited[u] = true;
        tin[u] = low[u] = ++timer;
        for(auto v:adj[u]){
            if(v == parent) continue;
            if(!visited[v]){
                dfs(v,u,adj,tin,low,visited,timer,bridges);
                low[u] = min(low[u],low[v]);
                if(low[v] > tin[u]){
                    bridges.push_back({u,v});
                }
            }else{
                low[u] = min(low[u],tin[v]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<vector<int>> bridges;
        vector<int>  tin(n,-1);
        vector<int> low(n,-1);
        vector<bool> visited(n,false);
        int timer = 0;
        for(auto &connection:connections)
        {
            int u = connection[0];
            int v= connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }   
        for(int i =0;i<n;i++){
            if(!visited[i]){
                dfs(i,-1,adj,tin,low,visited,timer,bridges);
            }
        }
        return bridges;
    }
};