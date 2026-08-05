class Solution {
    vector<int> parent,size;
     int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node]= findParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+= size[ulp_v];
        }else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0;i <= n;i++){
            parent[i] = i;
            size[i] = 1;
        }
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);

            if(ulp_u == ulp_v){
                return {u,v};
            }
            unionBySize(u,v);
        }
            return {};
    }
};