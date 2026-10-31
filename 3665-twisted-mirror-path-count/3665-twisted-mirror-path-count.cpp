class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, 0)));

        dp[0][1][0] = 1;
        dp[1][0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == m - 1 && j == n - 1)
                    continue;
                int right = dp[i][j][0];
                int down = dp[i][j][1];
                if (grid[i][j] == 0) {
                    int total = (right + down) % MOD;
                    if (j + 1 < n) {
                        dp[i][j + 1][0] = (dp[i][j + 1][0] + total) % MOD;
                    }
                    if (i + 1 < m) {
                        dp[i + 1][j][1] = (dp[i + 1][j][1] + total) % MOD;
                    }
                } else {
                    if (i + 1 < m) {
                        dp[i + 1][j][1] = (dp[i + 1][j][1] + right) % MOD;
                    }
                    if (j + 1 < n) {
                        dp[i][j + 1][0] = (dp[i][j + 1][0] + down) % MOD;
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    }
};