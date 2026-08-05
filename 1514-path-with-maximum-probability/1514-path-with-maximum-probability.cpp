class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0;i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }
        vector<double> prob(n,0.0);
        prob[start_node] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto [currProb,node] = pq.top();
            pq.pop();
            if(currProb < prob[node]) continue;
            for(auto &[adjNode,edgeProb]: adj[node]){
                if(currProb * edgeProb > prob[adjNode]){
                    prob[adjNode] = currProb * edgeProb;
                    pq.push({prob[adjNode],adjNode});
                }
            }
        }
        return prob[end_node];
    }
};