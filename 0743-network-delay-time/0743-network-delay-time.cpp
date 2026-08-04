class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [distance,node] = pq.top();
            pq.pop();

            for(auto [neighbour,weight] : adj[node]){
                if(distance > dist[node]) continue;
                if(distance + weight < dist[neighbour]){
                    dist[neighbour] = distance + weight;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }

        int ans = 0;
        for(int i = 1;i<=n ;i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};