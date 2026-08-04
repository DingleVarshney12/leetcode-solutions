class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //adjancy list with weights
        // from -> {to,price}
        vector<vector<pair<int,int>>> adj(n);
        for(auto& flight:flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adj[from].push_back({to,price});
        }

        //dist[node][stops]
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        //{cost,node,flightTaken}
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;


        dist[src][0] = 0;
        pq.push({0,src,0});

        
        while(!pq.empty()){
            auto [cost,node,stops] = pq.top();
            pq.pop();
            //found destination
            if(node == dst) return cost;

            //maximum flights already used
            if(stops == k+1){
                continue;
            }

            for(auto [neighbour,price]: adj[node]){
                int newStops = stops+1;
                int newCost = cost +price;
                if(newCost < dist[neighbour][newStops]){
                    dist[neighbour][newStops] = newCost;
                    pq.push({newCost,neighbour,newStops});
                }
            }
        }
        return -1;
    }
};