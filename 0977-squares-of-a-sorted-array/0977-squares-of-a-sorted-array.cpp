class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);

        int left = 0;
        int right = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                output[i] = leftSquare;
                left++;
            } else {
                output[i] = rightSquare;
                right--;
            }
        }

        return output;
    }
};
