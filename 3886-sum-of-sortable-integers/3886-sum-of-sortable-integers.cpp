class Solution {
#define f(i, a, n) for (int i = a; i <= n; i++)

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefMax(n + 1, 0), suffMin(n + 1, 1e9), prefDrop(n, 0);

        f(i, 0, n - 1) prefMax[i + 1] = max(prefMax[i], nums[i]);

        for (int i = n - 1; i >= 0; i--)
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        
        f(i, 1, n - 1) prefDrop[i] = prefDrop[i - 1] + (nums[i - 1] > nums[i]);

        auto check = [&](int k) -> bool {
            for (int i = 0; i < n; i += k) {
                int j = i + k - 1;
                int drops = prefDrop[j] - prefDrop[i];
                if (nums[j] > nums[i])
                    drops++;
                if (drops > 1)
                    return false;
                if (prefMax[i] > suffMin[i])
                    return false;
            }
            return true;
        };
        int ans = 0;
        f(k, 1, n) if (n % k == 0 && check(k)) ans += k;
        return ans;
    }
};