class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalCount = 0;
        for(auto &num:nums){
            totalCount+=num;
        }
        if(totalCount%2!=0) return false;
        int target = totalCount / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(auto num:nums){
            for(int j = target; j>=num;j--){
                dp[j] = dp[j] || dp[j - num];
                if(dp[target]) return true;
            }
        }
        return dp[target];

    }
};