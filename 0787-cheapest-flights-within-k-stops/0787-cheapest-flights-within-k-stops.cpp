class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // distance array : minimum cost to reachc each city
        vector<int> dist(n,INT_MAX);
        //source city cost is 0
        dist[src] = 0;
        // at most k stops can be use
        for(int i = 0;i <= k;i++){
            //copy previous iteration distance
            vector<int> temp = dist;

            // relax all edges
            for(auto &edge : flights){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                // if source city is reachable and a cheaper cost is found , update temp
                if(dist[u] != INT_MAX && dist[u] + wt < temp[v]){
                    temp[v] = min(temp[v],dist[u]+wt);
                }
            }
            // save updated distances
            dist = temp;
        }
        //destination is unreachable 
        if(dist[dst] == INT_MAX) return -1;
        //minimum cost to reach destination
        return dist[dst];
    }
};