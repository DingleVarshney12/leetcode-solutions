class Solution {
    
    // Time: O(2^n) approximately
    // Space: O(n) recursion stack
    int solveRecur(int i, int j, vector<int>& nums) {
        if (i > j)
            return 0;

        long long maxCoins = INT_MIN;

        for (int k = i; k <= j; k++) {
            long long coins = 1LL * nums[i - 1] * nums[k] * nums[j + 1] +
                              solveRecur(i, k - 1, nums) +
                              solveRecur(k + 1, j, nums);

            maxCoins = max(maxCoins, coins);
        }

        return maxCoins;
    }

    // Time: O(n^3)
    // Space: O(n^2) for DP + O(n) recursion stack
    int solveMemo(int i, int j, vector<int>& nums,
                  vector<vector<long long>>& dp) {
        
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long maxCoins = INT_MIN;

        for (int k = i; k <= j; k++) {
            long long coins = 1LL * nums[i - 1] * nums[k] * nums[j + 1] +
                              solveMemo(i, k - 1, nums, dp) +
                              solveMemo(k + 1, j, nums, dp);

            maxCoins = max(maxCoins, coins);
        }

        return dp[i][j] = maxCoins;
    }

    // Time: O(n^3)
    // Space: O(n^2) for DP table
    int solveTabu(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int i = n - 2; i >= 1; i--) {
            for (int j = i; j <= n - 2; j++) {

                long long maxCoins = INT_MIN;

                for (int k = i; k <= j; k++) {
                    long long coins =
                        1LL * nums[i - 1] * nums[k] * nums[j + 1] +
                        dp[i][k - 1] +
                        dp[k + 1][j];

                    maxCoins = max(maxCoins, coins);
                }

                dp[i][j] = maxCoins;
            }
        }

        return dp[1][n - 2];
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return solveTabu(nums);
    }
};