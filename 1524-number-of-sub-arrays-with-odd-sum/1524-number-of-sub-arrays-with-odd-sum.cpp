class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int even = 1, odd = 0;
        int ans = 0, parity = 0;
        for(int num : nums){
            parity ^= (num & 1);
            if(parity == 0) even++;
            else odd++;
            ans = (ans + ((parity % 2 == 0) ? odd : even)) % MOD;
        }
        return ans;
    }
};