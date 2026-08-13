class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(
            nums.begin(), nums.end(), 0
        );
        // Target totalSum se bahar hai
        if(abs(target) > totalSum)
            return 0;
        vector<vector<int>> dp(
            n + 1,
            vector<int>(2 * totalSum + 1, 0)
        );
        // current sum == target → 1 way
        dp[n][target + totalSum] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(int sum = -totalSum;
                sum <= totalSum;
                sum++) {
                int index = sum + totalSum;
                int posIndex =
                    sum + nums[i] + totalSum;
                int negIndex =
                    sum - nums[i] + totalSum;
                if(posIndex >= 0 &&
                   posIndex <= 2 * totalSum) {
                    dp[i][index] += dp[i + 1][posIndex];
                }
                if(negIndex >= 0 &&
                   negIndex <= 2 * totalSum) {
                    dp[i][index] += dp[i + 1][negIndex];
                }
            }
        }
        return dp[0][totalSum];
    }
};