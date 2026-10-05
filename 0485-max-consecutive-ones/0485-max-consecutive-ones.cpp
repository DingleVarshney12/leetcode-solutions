class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        int maxOnes = 0;
        while(right < n){
            if(nums[right] != 1){
                left = right + 1;
            }else {
                maxOnes = max(maxOnes, right - left + 1);
            }
            right++;
        }
        return maxOnes;
    }
};