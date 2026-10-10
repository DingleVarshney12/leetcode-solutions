class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        vector<int> diff;
        long long total = 0;
        int n = nums1.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            total += d;
            mx = max(mx, d);
        }
        long long k = (long long)k1 + k2;
        if (total <= k)
            return 0;

        int left = 0, right = mx;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long needed = 0;
            for (auto d : diff) {
                needed += max(0, d - mid);
            }
            if (needed <= k) {
                right = mid - 1;
            } else
                left = mid + 1;
        }
        int level = left;
        long long needed = 0;
        long long ans = 0;
        for (auto d : diff) {
            int reduced = min(d, level);
            ans += 1LL * reduced * reduced;
            needed += max(0, d - level);
        }
        long long remaining = k - needed;
        ans -= remaining * (2LL * level - 1);
        return ans;
    }
};