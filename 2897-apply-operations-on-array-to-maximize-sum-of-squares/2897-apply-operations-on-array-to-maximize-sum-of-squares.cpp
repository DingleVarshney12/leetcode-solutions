class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> bits(32, 0);

        for (auto& num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i)) {
                    bits[i]++;
                }
            }
        }
        long long output = 0;

        for (int i = 0; i < k; i++) {
            long long num = 0;
            for (int b = 0; b < 32; b++) {
                if (bits[b] > 0) {
                    num |= (1LL << b);
                    bits[b]--;
                }
            }
            output = (output + num * num) % MOD;
        }
        return output;
    }
};