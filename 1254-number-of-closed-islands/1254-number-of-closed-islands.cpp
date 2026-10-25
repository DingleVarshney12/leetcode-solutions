class Solution {
    int rows;
    int cols;
    bool dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= rows || j >= cols)
            return false;
        if (grid[i][j] == 1)
            return 1;
        grid[i][j] = 1;

        bool up = dfs(i - 1, j, grid);
        bool down = dfs(i + 1, j, grid);
        bool left = dfs(i, j - 1, grid);
        bool right = dfs(i, j + 1, grid);
        return up && down && left && right;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j, grid)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};