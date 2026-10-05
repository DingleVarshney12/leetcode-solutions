class NeighborSum {
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> coordinates;
    int n;

public:
    NeighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        this->grid = grid;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                coordinates[grid[i][j]] = {i, j};
            }
        }
    }

    int adjacentSum(int value) {
        auto [x, y] = coordinates[value];
        int sum = 0;
        // Up
        if (x - 1 >= 0) sum += grid[x - 1][y];

        // Left
        if (y - 1 >= 0) sum += grid[x][y - 1];

        // Down
        if (x + 1 < n) sum += grid[x + 1][y];

        // Right
        if (y + 1 < n) sum += grid[x][y + 1];

        return sum;
    }

    int diagonalSum(int value) {
        auto [x, y] = coordinates[value];

        int sum = 0;

        // Top-left
        if (x - 1 >= 0 && y - 1 >= 0) sum += grid[x - 1][y - 1];

        // Top-right
        if (x - 1 >= 0 && y + 1 < n) sum += grid[x - 1][y + 1];

        // Bottom-left
        if (x + 1 < n && y - 1 >= 0) sum += grid[x + 1][y - 1];

        // Bottom-right
        if (x + 1 < n && y + 1 < n) sum += grid[x + 1][y + 1];

        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */