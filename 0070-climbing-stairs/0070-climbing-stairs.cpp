class Solution {
public:
    int climbStairs(int n) {
       int prev1 = 1; // same as dp[i-1]
       int prev2 = 1; //same as dp[i-2]
       int curr = prev1; //dp[i]
       for(int i =2 ;i<=n;i++){
        curr = prev1 + prev2;
        prev2= prev1;
        prev1 = curr;
       }
       return curr;
    }
};