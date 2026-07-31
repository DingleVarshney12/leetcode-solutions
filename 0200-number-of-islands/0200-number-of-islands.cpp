class Solution {
    void DFS(int currRow,int currCol,int rows,int cols,vector<vector<char>>& grid){
        grid[currRow][currCol] = '0';
        int dr[] = {-1,1,0,0};
        int dc[]= {0,0,-1,1};
        for(int i = 0;i<4;i++){
            int newRow = currRow+dr[i];
            int newCol = currCol +dc[i];
            if((newRow>= 0 && newRow < rows) && 
            (newCol >= 0&& newCol < cols) && grid[newRow][newCol] == '1'){
                DFS(newRow,newCol,rows,cols,grid);
            }
        } 
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for(int i =0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j] == '1'){
                    count++;
                    DFS(i,j,rows,cols,grid);
                }
            }
        }
        return count;
    }
};