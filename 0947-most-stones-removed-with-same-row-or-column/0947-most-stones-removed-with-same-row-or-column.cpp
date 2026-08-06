class DisjointSet{
    vector<int> parent,rank,size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);

        for(int i = 0;i <= n;i++){
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node]= findParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int parentA = findParent(u);
        int parentB = findParent(v);
        if(parentA == parentB) return;
        if(rank[parentA] < rank[parentB]){
            parent[parentA] = parentB;
        }else if(rank[parentA] > rank[parentB]){
            parent[parentB] = parentA;
        }else{
            parent[parentB] = parentA;
            rank[parentA]++;
        }
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0,maxCol = 0;
        for(auto &it: stones){
            maxRow= max(maxRow,it[0]);
            maxCol= max(maxCol,it[1]);
        }
        int n = maxCol + maxRow + 2;
        DisjointSet ds(n);
        unordered_set<int> usedNodes;
        for(auto&stone:stones){
            int row = stone[0];
            int col= stone[1] + maxRow + 1;
            ds.unionBySize(row,col);
            usedNodes.insert(row);
            usedNodes.insert(col);
        }

        int components =0;

        for(auto node:usedNodes){
            if(ds.findParent(node) == node) components++;
        }
        return stones.size() - components;
    }
};