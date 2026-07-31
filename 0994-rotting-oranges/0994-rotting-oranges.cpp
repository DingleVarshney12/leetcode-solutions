class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten_oranges;
        int fresh_oranges = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int time = -1;
        for(int i =0 ; i< rows;i++){
            for(int j = 0;j < cols;j++){
                if(grid[i][j] == 2){
                    rotten_oranges.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh_oranges++;
                }
            }
        }
        if(fresh_oranges==0) return 0;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!rotten_oranges.empty()){
            int size = rotten_oranges.size();
            time++;
            while(size--){
                    auto [row,col] = rotten_oranges.front();
                    rotten_oranges.pop();
                    for(int i = 0 ; i < 4;i++){
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    if((newRow >= 0 && newRow < rows) && (newCol >= 0 && newCol < cols) && grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        fresh_oranges--;
                        rotten_oranges.push({newRow,newCol});
                    } 
                }
            }
        }
        return fresh_oranges == 0 ? time : -1;
    }   
};