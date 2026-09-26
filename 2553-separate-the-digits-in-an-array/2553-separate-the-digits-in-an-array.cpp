class Solution {
    void separate(int num, vector<int>& output) {
        while (num) {
            output.push_back(num % 10);
            num /= 10;
        }
    }

public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> output;
        for (int i = nums.size() - 1; i >= 0; i--) {
            separate(nums[i], output);
        }
        reverse(begin(output), end(output));
        return output;
    }
};