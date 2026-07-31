class Solution {
    void DFS(int city, vector<vector<int>> &isConnected,vector<bool>&visited){
        visited[city] = true;
        for(int i =0;i < isConnected.size();i++){
            if(isConnected[city][i] == 1 && !visited[i]){
                DFS(i,isConnected,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n=isConnected.size();
        vector<bool> visited(n,false);
        for(int i = 0;i< n;i++){
            if(!visited[i]){
                count++;
                DFS(i,isConnected,visited);
            }
        }
        return count;
    }
};