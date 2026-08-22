class Solution {

    // Recursion
    // Time  : O(2^n)
    // Space : O(n) -> Recursion stack
    int solveRecur(int i, int state, int k, vector<int>& prices) {

        if (i == prices.size() || k == 0)
            return 0;

        int profit = 0;

        if (state) {

            int buy = solveRecur(i + 1, 0, k, prices) - prices[i];

            int skip = solveRecur(i + 1, 1, k, prices);

            profit = max(buy, skip);
        } else {

            int sell = solveRecur(i + 1, 1, k - 1, prices) + prices[i];

            int hold = solveRecur(i + 1, 0, k, prices);

            profit = max(sell, hold);
        }

        return profit;
    }

    // Memoization
    // Time  : O(n * k)
    // Space : O(n * k) -> DP array + Recursion stack
    int solveMemo(int i, int state, int k, vector<int>& prices,
                  vector<vector<vector<int>>>& dp) {

        if (i == prices.size() || k == 0)
            return 0;

        if (dp[i][state][k] != -1)
            return dp[i][state][k];

        int profit = 0;

        if (state) {

            int buy = solveMemo(i + 1, 0, k, prices, dp) - prices[i];

            int skip = solveMemo(i + 1, 1, k, prices, dp);

            profit = max(buy, skip);
        } else {

            int sell = solveMemo(i + 1, 1, k - 1, prices, dp) + prices[i];

            int hold = solveMemo(i + 1, 0, k, prices, dp);

            profit = max(sell, hold);
        }

        return dp[i][state][k] = profit;
    }

    // Tabulation
    // Time  : O(n * k)
    // Space : O(n * k)
    int solveTabu(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--) {

            for (int state = 0; state <= 1; state++) {

                for (int ke = 1; ke <= k; ke++) {

                    if (state) {

                        int buy = dp[i + 1][0][ke] - prices[i];
                        int skip = dp[i + 1][1][ke];

                        dp[i][state][ke] = max(buy, skip);
                    } else {

                        int sell = dp[i + 1][1][ke - 1] + prices[i];

                        int hold = dp[i + 1][0][ke];

                        dp[i][state][ke] = max(sell, hold);
                    }
                }
            }
        }

        return dp[0][1][k];
    }

    // Space Optimization
    // Time  : O(n * k)
    // Space : O(k)
    int solveSpace(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        vector<vector<int>> next(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {

            for (int state = 0; state <= 1; state++) {

                for (int ke = 1; ke <= k; ke++) {

                    if (state) {

                        int buy = next[0][ke] - prices[i];
                        int skip = next[1][ke];

                        curr[state][ke] = max(buy, skip);
                    } else {

                        int sell = next[1][ke - 1] + prices[i];

                        int hold = next[0][ke];

                        curr[state][ke] = max(sell, hold);
                    }
                }
            }

            next = curr;
        }

        return next[1][k];
    }
   /*
   2K Formulation
   Time Complexity:  O(2^(n+k))
   Space complexity: O(n+k)
    int solve2k(int i,int state,int k, vector<int>& prices){
        if(i == prices.size() || state == 2*k) return 0;
        int take;
        if(state % 2 == 0)
            take = solve2k(i+1, state+1,k,prices) - prices[i];
        else
            take = solve2k(i+1, state+1,k,prices) + prices[i];

        int skip = solve2k(i+1, state,k,prices);
        return max(take,skip);
    } */
public:
    int maxProfit(int k, vector<int>& prices) { return solveSpace(k, prices); }
};