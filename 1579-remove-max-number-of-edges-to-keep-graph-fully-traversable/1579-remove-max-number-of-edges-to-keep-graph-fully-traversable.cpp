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
    bool unionBySize(int u,int v){
        int parentA = findParent(u);
        int parentB = findParent(v);
        if(parentA == parentB) return false;
        if(size[parentA] > size[parentB]){
            parent[parentB] = parentA;
            size[parentA]+= size[parentB];
        }else{
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
        }
        return true;
    }
};



class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n+1),bob(n+1);
        int removed = 0;
        for(auto &it:edges){
            int  type = it[0];
            int  u = it[1];
            int  v = it[2];
            if(type == 3){
                bool a = alice.unionBySize(u,v);
                bool b = bob.unionBySize(u,v);
                if(!a && !b)  removed++;
            }
        }
        for(auto &it:edges){
            int  type = it[0];
            int  u = it[1];
            int  v = it[2];
            if(type == 1){
                bool a = alice.unionBySize(u,v);
                if(!a) removed++;
            }
        }
        for(auto &it:edges){
            int  type = it[0];
            int  u = it[1];
            int  v = it[2];
            if(type == 2){
                bool b = bob.unionBySize(u,v);
                if(!b)removed++;
            }
        }
        int compAlice = 0, compBob = 0;
        for(int i=1;i <= n ; i++){
            if(alice.findParent(i) == i) compAlice++;
            if(bob.findParent(i) == i) compBob++;

            if(compAlice > 1 || compBob >1) return -1;
        }
        return removed;
    }
};