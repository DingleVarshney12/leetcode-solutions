class Solution {
    bool dfs(int node,vector<vector<int>>& adj,vector<int> & visited,vector<int>& pathVisited){
        if(pathVisited[node]) return false;
        if(visited[node]) return true;
        pathVisited[node] = true;
        visited[node] = true;
        for(auto neighbor: adj[node]){
            if(!dfs(neighbor,adj,visited,pathVisited)){
                return false;
            }
        }
        pathVisited[node] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto course: prerequisites){
            int a  = course[0];
            int b  = course[1];
            adj[b].push_back(a);
        }
        vector<int> pathVisited(numCourses,0);
        vector<int> visited(numCourses,0);
        for(int i = 0; i < numCourses;i++){
            if(!dfs(i,adj,visited,pathVisited)){
                return false;
            }
        }
        return true;
    }
};