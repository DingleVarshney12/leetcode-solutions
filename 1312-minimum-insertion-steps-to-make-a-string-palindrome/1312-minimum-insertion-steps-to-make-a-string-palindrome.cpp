class Solution {

    /*
    //Recursive Method:
    //Time complexity: O(2^n)
    //Recursive Space: O(n)

    int solve(int i,int j ,string s){
        if(i >= j)  return 0;
        if(s[i] == s[j] ) return solve(i+1,j-1,s);
        return 1 + min(
            solve(i+1,j,s),
            solve(i,j-1,s)
        );
    }
    */
    /*
    //Memorization Method:
    //Time complexity: O(n^2)
    //Recursive Space: O(n)
    //Space Complexity: O(n^2)

    int solve(int i,int j ,string s,vector<vector<int>>& dp){
        if(i >= j)  return 0;
        if(dp[i][j] != -1 ) return dp[i][j];
        if(s[i] == s[j] ) return  dp[i][j] = solve(i+1,j-1,s,dp);
        return dp[i][j] = 1 + min(
            solve(i+1,j,s,dp),
            solve(i,j-1,s,dp)
        );
    }
   */

public:
    int minInsertions(string s) {
        if(s.empty()) return 0;
        int n = s.length();
        /*
        //Tabulation Method:
        //Time complexity: O(n^2)
        //Space Complexity: O(n^2)

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j < n;j++){
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                else{
                    dp[i][j] = 1 + min(
                        dp[i+1][j],
                        dp[i][j-1]
                    );
                }
            }
        }
       return dp[0][n-1];
       */
       /*
        //Space Optimization:
        //Time complexity: O(n^2)
        //Space Complexity: O(n)
        */
       vector<int> dp(n,0);
       for(int i =n-1;i>=0;i--){
        int prev = 0;
        for(int j = i+1;j< n;j++){
            int temp = dp[j];
            if(s[i] == s[j]) dp[j] = prev;
            else{
                dp[j] = 1 + min(
                    dp[j],
                    dp[j-1]
                );
            }
            prev =temp;
        }
       }
       return dp[n-1];
    }
};