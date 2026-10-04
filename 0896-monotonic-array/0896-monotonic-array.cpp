class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() < 2) return true;
        int j = 0;
        int isIncreasing = 2;   // 2 : unknown , 1 : increasing , 0 : decreasing
        for(int i = 1; i < nums.size();i++){
            if(isIncreasing == 2){
                if(nums[j] < nums[i]){
                    isIncreasing = 1;
                }else if(nums[j] > nums[i]){
                    isIncreasing = 0;
                }
            }
            if(nums[j] < nums[i] && isIncreasing == 0) return false;
            if(nums[j] > nums[i] && isIncreasing == 1) return false;
            j++;
        }
        return true;
    }
};