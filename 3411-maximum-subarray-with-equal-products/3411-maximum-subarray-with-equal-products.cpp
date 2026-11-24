class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long p = 1, g = 0, l = 1;
            for (int j = i; j < n; j++) {
                if (p > LLONG_MAX / nums[j])
                    break;

                p *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = (l / gcd(l, (long long)nums[j])) * nums[j];
                if (p == l * g)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};