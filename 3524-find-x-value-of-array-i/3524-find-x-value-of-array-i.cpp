class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> output(k, 0);
        vector<int> dp(k, 0);

        for (auto& num : nums) {
            
            int numMod = num % k;
            vector<int> newDp(k, 0);
            newDp[numMod] += 1;

            for (int r = 0; r < k; r++) {

                int newReminder = (r * numMod) % k;
                newDp[newReminder] += dp[r];
            
            }

            for (int r = 0; r < k; r++) {
            
                output[r] += newDp[r];
            
            }
            dp = newDp;
        }

        return output;
    }
};