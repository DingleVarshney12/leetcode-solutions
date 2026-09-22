class Solution {
    int fibByDp(int i, vector<int>& dp) {
        if (i == 0)
            return 0;
        if (i == 1)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = fibByDp(i - 1, dp) + fibByDp(i - 2, dp);
    }

public:
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return fibByDp(n, dp);
    }
};