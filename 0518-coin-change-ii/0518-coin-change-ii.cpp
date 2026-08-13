class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<double> dp(amount+1,0);
        dp[0] =1;
        for(int i = n-1;i>=0;i--){
            for(int j =1;j<=amount;j++){
                if(coins[i] <= j) {
                    dp[j] = dp[j-coins[i]] + dp[j];
                }
            }
        }
        return dp[amount];
    }
};