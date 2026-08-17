class Solution {
    /*
    // Recursive Method 
    // Time Complexity : O(2^n)
    // Recursive Stack : O(n) 
    int solve(int index , int prevIndex ,vector<int>&nums){
        if(index == nums.size()) return 0;
        int skip = solve(index + 1,prevIndex,nums);
        int take = 0;
        if(prevIndex == -1 || nums[index] > nums[prevIndex]) {
            take = 1 + solve(index + 1,index,nums);
        }
        return max(take,skip);
    }*/
    /*
    // Memorization Method 
    // Time Complexity : O(n^2)
    // Space Complexity: O(n^2) 
    // Recursive Stack : O(n) 

    int solve(int index , int prevIndex ,vector<int>&nums,vector<vector<int>>& dp){
        if(index == nums.size()) return 0;
        if(dp[index][prevIndex +1 ] != -1) return dp[index][prevIndex +1];
        int skip = solve(index + 1,prevIndex,nums,dp);
        int take = 0;
        if(prevIndex == -1 || nums[index] > nums[prevIndex]) {
            take = 1 + solve(index + 1,index,nums,dp);
        }
        return dp[index][prevIndex + 1 ]= max(take,skip);
    }
    */

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

       /*
        // Tabulation Method 
        // Time Complexity : O(n^2)
        // Space Complexity: O(n^2)

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int idx = n-1;idx>=0;idx--){
            for(int prevIdx = idx -1;prevIdx >= -1 ;prevIdx--){
                int skip = dp[idx+1][prevIdx+1];
                int take = 0;
                if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
                    take = 1 + dp[idx+1][idx+1];
                }
                dp[idx][prevIdx+1] =max(take,skip); 
            }
        }
        return dp[0][0];
        */
        // Space Optimization
        // Time Complexity : O(n^2)
        // Space Complexity: O(n) 
        vector<int> dp(n+1,0);
         for(int idx = n-1;idx>=0;idx--){
            for(int prevIdx = idx -1;prevIdx >= -1 ;prevIdx--){
                int skip = dp[prevIdx+1];
                int take = 0;
                if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
                    take = 1 + dp[idx+1];
                }
                dp[prevIdx+1] =max(take,skip); 
            }
        }

        return dp[0];
    }
};