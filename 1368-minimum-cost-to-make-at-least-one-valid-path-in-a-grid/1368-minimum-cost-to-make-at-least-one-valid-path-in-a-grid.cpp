class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int INF = 1e9;
        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int,int>> dq;
        vector<vector<int>> dist(m,vector<int>(n,INF));
        vector<vector<int>> directions = {
            {0,1},   // right
            {0,-1},  // left
            {1,0},   // down
            {-1,0}   // up
        };
        dist[0][0] = 0;
        dq.push_front({0,0});
        while(!dq.empty()){
            auto [ row,col] = dq.front();
            dq.pop_front();

            for(int d = 0; d < 4; d++)
            {
                int nr = row + directions[d][0];
                int nc = col + directions[d][1];
                //check bounds
                if(nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    int cost = (grid[row][col] == d + 1) ? 0 : 1;
                    int newCost = dist[row][col] + cost;
                    if(newCost < dist[nr][nc])
                    {
                        dist[nr][nc] = newCost;

                        if(cost == 0)
                            dq.push_front({nr,nc});
                        else
                            dq.push_back({nr,nc});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};