class Solution {


    /*
    Recursive Method
    ``
    Time Complexity :O(2^m+n) // m -> word1.length & n -. word2.length
    Space Complexity: O(m+n) // recursion stack
    ``
    int solve(int i ,int j ,string word1, string word2){
        if(i == word1.length()) return word2.length() - j;
        if(j == word2.length()) return word1.length() - i;
        if(word1[i] == word2[j]) return solve(i+1,j+1,word1,word2);
        return 1 + min(solve(i,j+1,word1,word2),solve(i+1,j,word1,word2));
    }
    */
    /*
    Memorization method
    ```
    Time Complexity :O(m*n) // m -> word1.length & n -. word2.length
    Space Complexity: O(m*n)
    recursion stack: O(m+n) 
    ```
    int solve(int i ,int j ,string word1, string word2,vector<vector<int>>&dp){
        if(i == word1.length()) return word2.length() - j;
        if(j == word2.length()) return word1.length() - i;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j]= solve(i+1,j+1,word1,word2,dp);
        return dp[i][j] =  1 + min(solve(i,j+1,word1,word2,dp),solve(i+1,j,word1,word2,dp));
    }
    */

public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        /*
        Tablation Method
        ````
        Time Complexity :O(m*n) 
        Space Complexity: O(m*n)
        ````
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 0; i <= m; i++) dp[i][n] = m - i;
        for(int j = 0; j <= n; j++) dp[m][j] = n - j;
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    dp[i][j] = 1 + min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        */  
        /*
        Space Optimization method
        `````
        Time Complexity :O(m*n) 
        Space Complexity: O(n)
        `````
        */
        vector<int> dp(n+1);
        for(int j = 0; j <= n; j++) dp[j] = n - j;
        for(int i = m-1;i>=0;i--){
            int dia = dp[n]; 
            dp[n] = m - i; 
            for(int j = n-1;j>=0;j--){
                int temp = dp[j];
                if(word1[i] == word2[j]) {
                    dp[j] = dia;
                }else{
                    dp[j] = 1 + min(dp[j],dp[j+1]);
                }
                dia = temp;
            }
        }

        return dp[0];
    }
};