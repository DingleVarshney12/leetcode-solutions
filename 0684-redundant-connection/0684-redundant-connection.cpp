class Solution {
    bool DFS(int node ,int target,vector<vector<int>>& adj,vector<int>& visited){
        if(node == target) return true;
        visited[node] = 1;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                if(DFS(neighbour,target,adj,visited)){
                    return true;
                }
            }
        }
        return false;
        
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() +1;
        vector<vector<int>> adj(n+1);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            vector<int> visited(n+1,0);
            if(DFS(u,v,adj,visited)){
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};