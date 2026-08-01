class Solution {
    bool DFS(int node,vector<vector<int>>& graph,vector<int> &color){
        for(int neighbour:graph[node]){
            
            if(color[neighbour] == -1){
                color[neighbour] = 1 - color[node];
                
                if(!DFS(neighbour,graph,color)) return false;
            }
            else if(color[node] == color[neighbour]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0; i < n;i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!DFS(i,graph,color)) return false;
            }
        }
        return true;
    }
};