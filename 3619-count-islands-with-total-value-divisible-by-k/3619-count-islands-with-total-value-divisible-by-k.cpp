class Solution {
    int rows,cols;
    long long dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= rows || j >= cols) return 0;
        if(grid[i][j] == 0) return 0;
        int curr = grid[i][j];
        grid[i][j] = 0;
        long long up = dfs(i-1,j,grid);
        long long down = dfs(i+1,j,grid);
        long long left = dfs(i,j-1,grid);
        long long right = dfs(i,j+1,grid);
        return curr + up + down + left + right;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if(grid.empty() || grid[0].empty()) return 0;
        rows = grid.size();
        cols = grid[0].size();
        int count = 0;
        for(int i =0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != 0){
                    long long x = dfs(i,j,grid);
                    if(x % k == 0) count++;
                }
            }
        }
        return count;
    }
};