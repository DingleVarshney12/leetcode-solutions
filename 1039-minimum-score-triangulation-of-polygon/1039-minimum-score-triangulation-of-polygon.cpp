class Solution {

    // Time: O(3^n) approximately
    // Space: O(n) recursion stack
    int solveRecur(int i, int j, vector<int>& values) {
        if (j - i < 2) return 0;

        int min_score = 1e9;

        for (int k = i + 1; k < j; k++) {
            int score = values[i] * values[k] * values[j]
                      + solveRecur(i, k, values)
                      + solveRecur(k, j, values);

            min_score = min(min_score, score);
        }

        return min_score;
    }


    // Time: O(n^3)
    // Space: O(n^2) DP + O(n) recursion stack
    // Auxiliary Space: O(n^2)

    int solveMemo(int i, int j, vector<int>& values,
                  vector<vector<long long>>& dp) {

        if (j - i < 2) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int min_score = 1e9;

        for (int k = i + 1; k < j; k++) {
            int score = values[i] * values[k] * values[j]
                      + solveMemo(i, k, values, dp)
                      + solveMemo(k, j, values, dp);

            min_score = min(min_score, score);
        }

        return dp[i][j] = min_score;
    }

    // Time: O(n^3)
    // Space: O(n^2)
    int solveTabu(vector<int>& values) {
        int n = values.size();

        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {

                long long min_score = LLONG_MAX;

                for (int k = i + 1; k < j; k++) {

                    long long score =
                        values[i] * values[k] * values[j]
                        + dp[i][k]
                        + dp[k][j];

                    min_score = min(min_score, score);
                }

                dp[i][j] = min_score;
            }
        }

        return dp[0][n - 1];
    }


public:
    int minScoreTriangulation(vector<int>& values) {
        return solveTabu(values);
    }
};