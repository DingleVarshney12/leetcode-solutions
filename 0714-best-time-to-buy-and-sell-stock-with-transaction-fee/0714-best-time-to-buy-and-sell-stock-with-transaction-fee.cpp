class Solution {

    // Recursion
    // Time: O(2^n)
    // Space: O(n) -> Recursion stack
    int solveRecur(int i, int state, int fee, vector<int>& prices) {
        if (i == prices.size())
            return 0;

        int profit = 0;
        if (state) {
            int buy = solveRecur(i + 1, 0, fee, prices) - prices[i];
            int skip = solveRecur(i + 1, 1, fee, prices);
            profit = max(buy, skip);
        } else {
            int sell = solveRecur(i + 1, 1, fee, prices) + prices[i] - fee;
            int hold = solveRecur(i + 1, 0, fee, prices);
            profit = max(sell, hold);
        }
        return profit;
    }

    // Memoization
    // Time: O(n)
    // Space: O(n) -> DP array + Recursion stack
    int solveMemo(int i, int state, int fee, vector<int>& prices,
                  vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;

        if (dp[i][state] != -1)
            return dp[i][state];
        
        int profit = 0;
        if (state) {
            int buy = solveMemo(i + 1, 0, fee, prices, dp) - prices[i];
            int skip = solveMemo(i + 1, 1, fee, prices, dp);
            profit = max(buy, skip);
        } else {
            int sell = solveMemo(i + 1, 1, fee, prices, dp) + prices[i] - fee;
            int hold = solveMemo(i + 1, 0, fee, prices, dp);
            profit = max(sell, hold);
        }
        return dp[i][state] = profit;
    }

    // Tabulation
    // Time: O(n)
    // Space: O(n)
    int solveTabu(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int state = 0; state <= 1; state++) {
                if (state) {
                    int buy = dp[i + 1][0] - prices[i];
                    int skip = dp[i + 1][1];
                    dp[i][state] = max(buy, skip);
                } else {
                    int sell = dp[i + 1][1] + prices[i] - fee;
                    int hold = dp[i + 1][0];
                    dp[i][state] = max(sell, hold);
                }
            }
        }
        return dp[0][1];
    }

    // Space Optimization
    // Time: O(n)
    // Space: O(1)
    int solveSpace(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int state = 0; state <= 1; state++) {

                if (state) {
                    int buy = next[0] - prices[i];
                    int skip = next[1];
                    curr[state] = max(buy, skip);
                } else {
                    int sell = next[1] + prices[i] - fee;
                    int hold = next[0];
                    curr[state] = max(sell, hold);
                }
            }
            next = curr;
        }
        return next[1];
    }
        int solveGreedy(vector<int>& prices, int fee){
            int cash = 0;
            int hold = -prices[0];
            for (int i = 1; i < prices.size(); i++) {
                int prevCash = cash;
                // Sell
                cash = max(cash, hold + prices[i] - fee);
                // Buy
                hold = max(hold, prevCash - prices[i]);
            }
            return cash;
        }
public:
    int maxProfit(vector<int>& prices, int fee) {
        return solveGreedy(prices, fee);
    }
};