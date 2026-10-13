class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());

        long long ans = 0;
        int mid = n / 2;
        for (int i = 0; i < mid; i++) {
            ans -= nums[i];
        }

        for (int i = mid; i < n; i++) {
            ans += nums[i];
        }
        return ans;
    }
};