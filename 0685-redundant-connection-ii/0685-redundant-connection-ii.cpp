class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0;i <= n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node]= findParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int parentA = findParent(u);
        int parentB = findParent(v);
        if(parentA == parentB) return;
        if(size[parentA] > size[parentB]){
            parent[parentB] = parentA;
            size[parentA]+= size[parentB];
        }else{
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
        }
    }
};



class Solution {
public:
        vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges){
        int n = edges.size();
        vector<int> parent(n+1,0);
        vector<int> candidate1,candidate2;
        int candidate2Index = -1;
        for(int i = 0;i<n;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            if(parent[v] == 0)
            {
                parent[v] = u;
            }
            else
            {
                candidate1 = {parent[v], v};
                candidate2 = {u, v};
                candidate2Index = i;
            }
        }
        DisjointSet ds(n+1);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            if(i == candidate2Index)
                continue;
            if(ds.findParent(u) == ds.findParent(v))
            {
                    if(candidate1.empty()) return { u,v };
                    return candidate1;
            }else{
                ds.unionBySize(u,v);
            }
        }
        return candidate2;
    }
};