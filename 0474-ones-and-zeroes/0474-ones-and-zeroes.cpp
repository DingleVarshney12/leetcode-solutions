class Solution {
    // Recursion Method
    // Time: O(2^N)
    // Space: O(N)
    int solveRecur(int i, int z, int o, vector<pair<int, int>>& count) {
        if (i == count.size())
            return 0;

        int take = 0;
        int notTake = solveRecur(i + 1, z, o, count);
        if (count[i].first <= z && count[i].second <= o) {
            take = 1 + solveRecur(i + 1, z - count[i].first,
                                  o - count[i].second, count);
        }

        return max(take, notTake);
    }
    // Memorization Method
    // Time: O(N * M * K)
    // Space: O(N * M * K)
    int solveMemo(int i, int z, int o, vector<pair<int, int>>& count,
                  vector<vector<vector<int>>>& dp) {
        if (i == count.size())
            return 0;

        if (dp[i][z][o] != -1)
            return dp[i][z][o];
        int take = 0;
        int notTake = solveMemo(i + 1, z, o, count, dp);
        if (count[i].first <= z && count[i].second <= o) {
            take = 1 + solveMemo(i + 1, z - count[i].first, o - count[i].second,
                                 count, dp);
        }

        return dp[i][z][o] = max(take, notTake);
    }
    // Tabulation method
    // Time: O(N * M * K)
    // Space: O(N * M * K)

    int solveTabu(int m, int n, vector<pair<int, int>>& count) {
        int size = count.size();
        vector<vector<vector<int>>> dp(
            size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = size - 1; i >= 0; i--) {
            int zero = count[i].first, one = count[i].second;
            for (int z = 0; z <= m; z++) {
                for (int o = 0; o <= n; o++) {
                    int notTake = dp[i + 1][z][o];
                    int take = 0;
                    if (zero <= z && one <= o) {

                        take = 1 + dp[i + 1][z - zero][o - one];
                    }
                    dp[i][z][o] = max(take, notTake);
                }
            }
        }
        return dp[0][m][n];
    }
    // Space optimization
    // Time: O(N * M * K)
    // Space: O(M * K)
    int solveSpace(int m, int n, vector<pair<int, int>>& count) {
        int size = count.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < size; i++) {
            int zero = count[i].first, one = count[i].second;
            for (int z = m; z >= zero; z--) {
                for (int o = n; o >= one; o--) {
                    int notTake = dp[z][o];
                    int take = 1 + dp[z - zero][o - one];
                    dp[z][o] = max(take, notTake);
                }
            }
        }
        return dp[m][n];
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<pair<int, int>> count(size, {0, 0});
        vector<vector<vector<int>>> dp(
            size, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        for (int i = 0; i < strs.size(); i++) {
            for (char ch : strs[i]) {
                if (ch == '0') {
                    count[i].first++;
                } else {
                    count[i].second++;
                }
            }
        }

        return solveSpace(m, n, count);
    }
};