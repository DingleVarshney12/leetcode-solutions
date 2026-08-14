class Solution {
    /*

    ```
    Memorization DP 
    Time Complexit: O(m*n)
    space complexity: O(m*n)
    Recursion stack : O(m+n)
    ```


    int solve(int i,int j,string text1, string text2,vector<vector<int>>& dp){
        if(text1.length() == i || text2.length() == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]) return dp[i][j] = 1 + solve(i+1,j+1,text1,text2,dp);
        return dp[i][j] =max(solve(i+1,j,text1,text2,dp),solve(i,j+1,text1,text2,dp));

    }
    */
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.length();
        int n = text2.length();
        /*
        ````
        Tabulation Method 
        Time Complexity : O(m*n)
        Space Complexity: O(m*n)
        ````

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = m -1; i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
        */

        /*
        `````
        1D DP
        Time Complexity : O(m*n)
        Space Complexity: O(n)
        `````
        */
        
        vector<int> dp(n+1,0);
        for(int i = m -1; i>=0;i--){
            int dia = 0;
            for(int j = n-1;j>=0;j--){
                int temp = dp[j];
                if(text1[i] == text2[j]){
                    dp[j] = 1 + dia;
                }else{
                    dp[j] = max(dp[j+1],dp[j]);
                }
                dia = temp;
            }
        }
        return dp[0];

    }
};