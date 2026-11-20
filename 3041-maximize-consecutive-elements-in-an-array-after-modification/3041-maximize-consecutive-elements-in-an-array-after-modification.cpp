class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        int result = 1;

        auto search = [&](int start, int target) {
            int j = lower_bound(begin(nums) + start, end(nums), target) -
                    begin(nums);
            if (j < n && nums[j] == target) {
                return j;
            }
            return -1;
        };
        for (int i = n - 1; i >= 0; i--) {
            for (int inc = 0; inc <= 1; inc++) {
                
                int curr = nums[i] + inc;
                int len = 1;

                int j = search(i + 1, curr + 1);

                if (j != -1)
                    len = max(len, 1 + dp[j][0]);

                j = search(i + 1, curr);
                if (j != -1)
                    len = max(len, 1 + dp[j][1]);

                dp[i][inc] = len;
                result = max(len, result);
            }
        }
        return result;
    }
};