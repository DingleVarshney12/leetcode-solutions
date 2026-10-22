class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int asc = 1, des = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == (nums[i - 1] + 1) % n)
                asc++;

            if (nums[i - 1] == (nums[i] + 1) % n)
                des++;
        }

        if (asc == n) {
            return nums.front() ?  min(nums.front() + 2, n - nums.front()) : 0;
        }

        if (des == n) {
            return min(nums.back(), n - nums.back()) + 1;
        }

        return -1;
    }
};