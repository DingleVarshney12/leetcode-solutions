class Solution {
#define LL long long
using T = tuple<LL,int,int>;
#define min_heap priority_queue<T,vector<T>,greater<T>>
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& edge:edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].emplace_back(v,w);
        }
        
        const LL INF = LLONG_MAX;
        vector<vector<LL>> dist(n,vector<LL>(k + 1, INF ));
        min_heap pq; 
        dist[0][1] = 0;
        pq.emplace(0,0,1);

        while(!pq.empty()){
            auto [cost,node,count] = pq.top();
            pq.pop();   

            if (cost != dist[node][count]) continue;

            if(node == n - 1) return (int)cost; 

            for(auto& [neighbor,weight]: adj[node]){

                int newCount = labels[node] == labels[neighbor] ? count + 1 : 1;

                if(newCount > k) continue;
                
                LL newCost = cost + weight;
                
                if (newCost < dist[neighbor][newCount]) {
                    dist[neighbor][newCount] = newCost;
                    pq.emplace(newCost,neighbor,newCount);
                }

            }
        }
        return -1;
    }
};