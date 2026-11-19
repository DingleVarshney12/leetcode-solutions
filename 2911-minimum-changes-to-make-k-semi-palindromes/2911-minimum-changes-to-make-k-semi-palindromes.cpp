class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, n));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    for (int x = 0; x < d; x++) {
                        int l = i + x;
                        int r = j - d + 1 + x;

                        while (l < r) {
                            if (s[l] != s[r])
                                changes++;

                            l += d;
                            r -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        const int INF = 1e9;

        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            for (int i = 2 * parts; i <= n; i++) {

                for (int p = 2 * (parts - 1);
                     p <= i - 2; p++) {

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[p][parts - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
