class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<int> minDist(V,INT_MAX);
        minDist[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<bool> visited(V,false);
        int ans= 0;
        while(!pq.empty()){
            auto [cost,u] = pq.top();
            pq.pop();
            if(visited[u]) continue;
            visited[u] = true;
            ans += cost;
            for(int v = 0;v<V;v++){
               if(visited[v]) continue;
               int manhattan = abs(points[u][0] - points[v][0]) +abs(points[u][1]-points[v][1]);

               if(manhattan < minDist[v]){
                minDist[v] =manhattan;
                pq.push({manhattan,v});
               }
            }
        }
        return ans;     
    }
}; 