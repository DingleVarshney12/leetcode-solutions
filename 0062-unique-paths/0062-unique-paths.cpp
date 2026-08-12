class Solution {
public:
    int uniquePaths(int m, int n) {

        // Sirf ek row ko store karenge
        // dp[j] = current column tak pahunchne ke ways
        vector<int> dp(n, 1);

        for(int i = 1; i < m; i++) {

            for(int j = 1; j < n; j++) {

                // dp[j] = upar wale cell ke ways
                // dp[j-1] = left wale cell ke ways
                // Dono ko add karke current cell ke total ways milenge
                dp[j] = dp[j] + dp[j-1];
            }
        }

        return dp[n-1];
    }
};