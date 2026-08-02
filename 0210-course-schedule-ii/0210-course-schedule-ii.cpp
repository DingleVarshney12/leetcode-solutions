class Solution {
    bool dfs(int curr,vector<vector<int>> &adj,vector<int> &visited,vector<int> &pathVisited,stack<int>& st){
        if(pathVisited[curr]) return false;
        if(visited[curr]) return true;

        visited[curr] = true;
        pathVisited[curr] = true;
        
        for(auto neighbor: adj[curr]){
            if(!dfs(neighbor,adj,visited,pathVisited,st)){
                return false;
            }
        }
        
        pathVisited[curr] = false;
        st.push(curr);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {


        vector<vector<int>> adj(numCourses);
        for(auto course: prerequisites){
            adj[course[1]].push_back(course[0]);
        }


        stack<int> st;
        vector<int> visited(numCourses,0);
        vector<int> pathVisited(numCourses,0);
        for(int i = 0 ;i < numCourses;i++){
            if(!dfs(i,adj,visited,pathVisited,st)){
                return {};
            }
        } 


        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};