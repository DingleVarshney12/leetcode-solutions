class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        vector<vector<int>> dist(rows,vector<int>(cols,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        dist[0][0] = 0;
        pq.push({0,0,0});

        while(!pq.empty()){
            auto [effort,row,col] = pq.top();
            pq.pop();
            for(int i =0; i < 4;i++){
                int newRow = row + dr[i];
                int newCol = col + dc[i];
            
                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols ){
                    
                    if (effort > dist[row][col]) continue;

                    int newEffort = max(effort,abs(heights[row][col]-heights[newRow][newCol]));

                    if(newEffort < dist[newRow][newCol]){
                        dist[newRow][newCol] = newEffort;
                        pq.push({newEffort,newRow,newCol});
                    }
                }
            }
        }
        return dist[rows-1][cols-1];
    }
};