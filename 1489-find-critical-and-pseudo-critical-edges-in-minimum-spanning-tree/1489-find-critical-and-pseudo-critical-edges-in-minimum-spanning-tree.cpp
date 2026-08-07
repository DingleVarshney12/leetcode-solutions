class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int parentA = findParent(u);
        int parentB = findParent(v);
        if (parentA == parentB)
            return;
        if (size[parentA] > size[parentB])
        {
            parent[parentB] = parentA;
            size[parentA] += size[parentB];
        }
        else
        {
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
        }
    }
};


class Solution {
    int MST(int n,vector<vector<int>>& edges,int skip,int force){

        int mstWeight = 0,edgesTaken=0;
        DisjointSet ds(n);
        if(force != -1)
        {
            for(auto &edge : edges)
            {
                if(edge[3] == force)
                {
                    int u = edge[0];
                    int v = edge[1];
                    int wt = edge[2];

                    ds.unionBySize(u, v);
                    mstWeight += wt;
                    edgesTaken++;

                    break;
                }
            }
        }
        for(int i = 0;i<edges.size();i++){
                 if(skip == edges[i][3]) continue;
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                if (ds.findParent(u) != ds.findParent(v))
                {
                    ds.unionBySize(u, v);
                    mstWeight += wt;
                    edgesTaken++;
                }
            if (edgesTaken == n - 1) break;
        }
        if(edgesTaken != n-1) return INT_MAX;
        return mstWeight;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](auto &a,auto&b){
            return a[2] < b[2];
        });
        vector<int> critical,pscritical;
        int originalMST = MST(n,edges,-1,-1);

        for(int i = 0;i < edges.size();i++){
            int originalIndex = edges[i][3];
            if(originalMST < MST(n,edges,originalIndex,-1)){
                critical.push_back(edges[i][3]);
            }
            else if(originalMST == MST(n,edges,-1,originalIndex)){
                pscritical.push_back(edges[i][3]);
            }
        }

        return {critical,pscritical};
        
    }
}; 