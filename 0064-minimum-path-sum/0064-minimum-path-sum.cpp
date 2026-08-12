class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n);

        dp[0] = grid[0][0];

        // First row
        for(int j = 1; j < n; j++) {
            dp[j] = dp[j-1] + grid[0][j];
        }

        for(int i = 1; i < m; i++) {

            // First column - sirf upar se aa sakte hain
            dp[0] += grid[i][0];

            for(int j = 1; j < n; j++) {

                // dp[j] = upar
                // dp[j-1] = left
                dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }

        return dp[n-1];
    }
};
