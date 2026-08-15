class Solution {
    int calculateASCII(int i, string s) {
        int sum = 0;
        for(int k = i; k < s.length(); k++) sum += s[k];
        return sum;
    }

    /*
    ``
    1. RECURSION
    Time Complexity:
        O(2^(m+n))
    Recursion Stack:
        O(m+n)
    ``

    int solve(int i, int j, string s1, string s2) {
        if(i == s1.length()) return calculateASCII(j, s2);
        if(j == s2.length()) return calculateASCII(i, s1);
        if(s1[i] == s2[j]) return solve(i+1, j+1, s1, s2);
        return min(
            s1[i] + solve(i+1, j, s1, s2),
            s2[j] + solve(i, j+1, s1, s2)
        );
    }
    */


    /*
    ```
    2. MEMOIZATION
    Time:  O(m*n*(m+n))
    Space: O(m*n) + O(m+n) recursion stack
    ```
    int solve(int i, int j, string s1, string s2,
              vector<vector<int>>& dp) {
        if(i == s1.length()) return calculateASCII(j, s2);
        if(j == s2.length()) return calculateASCII(i, s1);
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j])return dp[i][j] = solve(i+1, j+1, s1, s2, dp);
        return dp[i][j] = min(
            s1[i] + solve(i+1, j, s1, s2, dp),
            s2[j] + solve(i, j+1, s1, s2, dp)
        );
    }
    */


public:

    int minimumDeleteSum(string s1, string s2) {

        int m = s1.length();
        int n = s2.length();

        /*
        ````
        3. 2D TABULATION
        Time:  O(m*n)
        Space: O(m*n)
        ````

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = m-1; i >= 0; i--) dp[i][n] = dp[i+1][n] + s1[i];
        for(int j = n-1; j >= 0; j--) dp[m][j] = dp[m][j+1] + s2[j];

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                }
                else {
                    dp[i][j] = min(
                        s1[i] + dp[i+1][j],
                        s2[j] + dp[i][j+1]
                    );
                }
            }
        }
        return dp[0][0];
        */


        /*
        `````
        4. 1D SPACE OPTIMIZATION
        Time:  O(m*n)
        Space: O(n)
        `````
        */

        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--) dp[i] = dp[i+1] + s2[i];
        for(int i = m-1; i >= 0; i--) {
            int dia = dp[n];

            // Update last column:
            // dp[i][n] = dp[i+1][n] + ASCII(s1[i])
            dp[n] += s1[i]; // taken help from AI

            for(int j = n-1; j >= 0; j--) {
                int temp = dp[j];
                if(s1[i] == s2[j]) {
                    dp[j] = dia;
                }
                else {
                    dp[j] = min(
                        s1[i] + dp[j], 
                        s2[j] + dp[j+1] 
                    );
                }
                dia = temp;
            }
        }
        return dp[0];
    }
};