class Solution {
    /*
    Recursive Method:
    Time Complexity  : O(2^n)
    Space Complexity : O(n) // Recursion Stack
    */
    int solveRecu(int i, int state, vector<int>& prices) {
        if (i == prices.size())
            return 0;

        int profit = 0;

        if (state == 0) {
            int buy = solveRecu(i + 1, 1, prices) - prices[i];
            int skip = solveRecu(i + 1, 0, prices);
            profit = max(buy, skip);
        } else if (state == 1) {
            int sell = solveRecu(i + 1, 2, prices) + prices[i];
            int hold = solveRecu(i + 1, 1, prices);
            profit = max(sell, hold);
        } else {
            profit = solveRecu(i + 1, 0, prices);
        }

        return profit;
    }

    /*
    Memoization:
    Time Complexity  : O(n * 3) = O(n)
    Space Complexity : O(n * 3) + O(n) = O(n)
                       DP Table + Recursion Stack
    */
    int solveMemo(int i, int state, vector<int>& prices,
                  vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;

        if (dp[i][state] != -1)
            return dp[i][state];

        int profit = 0;

        if (state == 0) {
            int buy = solveMemo(i + 1, 1, prices, dp) - prices[i];
            int skip = solveMemo(i + 1, 0, prices, dp);
            profit = max(buy, skip);
        } else if (state == 1) {
            int sell = solveMemo(i + 1, 2, prices, dp) + prices[i];
            int hold = solveMemo(i + 1, 1, prices, dp);
            profit = max(sell, hold);
        } else {
            profit = solveMemo(i + 1, 0, prices, dp);
        }

        return dp[i][state] = profit;
    }

    /*
    Tabulation:
    Time Complexity  : O(n * 3) = O(n)
    Space Complexity : O(n * 3) = O(n)
    */
    int solveTabu(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int state = 0; state <= 2; state++) {

                if (state == 0) {
                    int buy = dp[i + 1][1] - prices[i];
                    int skip = dp[i + 1][0];
                    dp[i][state] = max(buy, skip);
                } else if (state == 1) {
                    int sell = dp[i + 1][2] + prices[i];
                    int hold = dp[i + 1][1];
                    dp[i][state] = max(sell, hold);
                } else {
                    dp[i][state] = dp[i + 1][0];
                }
            }
        }

        return dp[0][0];
    }

    /*
    Space Optimized:
    Time Complexity  : O(n * 3) = O(n)
    Space Complexity : O(3) + O(3) = O(1)
                       Current + Next Array
    */
    int solveSpace(vector<int>& prices) {
        int n = prices.size();

        vector<int> next(3, 0);
        vector<int> curr(3, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int state = 0; state <= 2; state++) {

                if (state == 0) {
                    int buy = next[1] - prices[i];
                    int skip = next[0];
                    curr[state] = max(buy, skip);
                } else if (state == 1) {
                    int sell = next[2] + prices[i];
                    int hold = next[1];
                    curr[state] = max(sell, hold);
                } else {
                    curr[state] = next[0];
                }
            }
            next = curr;
        }

        return next[0];
    }

public:
    int maxProfit(vector<int>& prices) { return solveSpace(prices); }
};