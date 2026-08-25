class Solution {

    /*
    Recursive Method:
    Time Complexity: O(2^m)
    Space Complexity: O(m) // Recursive Stack
    */
    long long solveRecur(int i,int j,string s, string t){
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;

        if(s[i] == t[j])
            return solveRecur(i+1,j+1,s,t) + solveRecur(i+1,j,s,t);
        else
            return solveRecur(i+1,j,s,t);
    }

    /*
    Memoization:
    Time Complexity: O(m*n)
    Space Complexity: O(m*n) + O(m) // DP + Recursive Stack
    */
    long long solveMemo(int i,int j,string s, string t,
                        vector<vector<long long>>& dp){
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j])
            return dp[i][j] = solveMemo(i+1,j+1,s,t,dp)
                            + solveMemo(i+1,j,s,t,dp);
        else
            return dp[i][j] = solveMemo(i+1,j,s,t,dp);
    }

    /*
    Tabulation:
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
    */
    long long solveTabu(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));

        // Base Case: t is completely matched
        for(int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                if(s[i] == t[j]) {
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                }
                else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }

        return dp[0][0];
    }

    /*
    Space Optimization:
    Time Complexity: O(m*n)
    Space Complexity: O(n)
    */
    long long solveSpace(string s, string t){
        int m = s.length();
        int n = t.length();

        vector<long long> curr(n+1,0);
        vector<long long> next(n+1,0);

        // Base Case: t is completely matched
        next[n] = 1;
        curr[n] = 1;

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){

                if(s[i] == t[j]){
                    curr[j] = (__int128) next[j+1] + next[j];
                }
                else{
                    curr[j] = next[j];
                }
            }

            next = curr;
        }

        return next[0];
    }

public:
    int numDistinct(string s, string t) {
        return solveSpace(s,t);
    }
};