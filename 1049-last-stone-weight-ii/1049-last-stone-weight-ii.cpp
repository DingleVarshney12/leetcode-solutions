class Solution {
    /*
    Recursive Method :
    Time Complexity : O(2^n)
    Space Complexity : O(n) // recursive stack
    */
    int solveRecur(int i, int target, vector<int>& stones) {
        if (target == 0 || i == stones.size())
            return 0;

        if (stones[i] <= target) {
            int take =
                stones[i] + solveRecur(i + 1, target - stones[i], stones);
            int nottake = solveRecur(i + 1, target, stones);

            return max(take, nottake);
        } else {
            return solveRecur(i + 1, target, stones);
        }
    }

    /*
    Memoization Method :
    Time Complexity : O(n * target)
    Space Complexity : O(n * target)
    */
    int solveMemo(int i, int target, vector<int>& stones,
                  vector<vector<int>>& dp) {
        if (target == 0 || i == stones.size())
            return 0;

        if (dp[i][target] != -1)
            return dp[i][target];

        if (stones[i] <= target) {
            int take =
                stones[i] + solveMemo(i + 1, target - stones[i], stones, dp);

            int nottake = solveMemo(i + 1, target, stones, dp);

            return dp[i][target] = max(take, nottake);
        } else {
            return dp[i][target] = solveMemo(i + 1, target, stones, dp);
        }
    }

    /*
    Tabulation Method :
    Time Complexity : O(n * target)
    Space Complexity : O(n * target)
    */
    int solveTabu(int target, int n, vector<int>& stones) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int tar = 0; tar <= target; tar++) {

                if (stones[i] <= tar) {
                    int take = stones[i] + dp[i + 1][tar - stones[i]];

                    int nottake = dp[i + 1][tar];

                    dp[i][tar] = max(take, nottake);
                } else {
                    dp[i][tar] = dp[i + 1][tar];
                }
            }
        }

        return dp[0][target];
    }

    /*
    Space Optimized Method :
    Time Complexity : O(n * target)
    Space Complexity : O(target)
    */
    int solveSpace(int target, int n, vector<int>& stones) {
        vector<int> dp(target + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int tar = target; tar >= 0; tar--) {

                if (stones[i] <= tar) {
                    int take = stones[i] + dp[tar - stones[i]];

                    int nottake = dp[tar];

                    dp[tar] = max(take, nottake);
                }
            }
        }

        return dp[target];
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;

        for (auto& stone : stones) {
            total += stone;
        }

        int target = total / 2;

        int best = solveSpace(target, n, stones);

        return total - 2 * best;
    }
};