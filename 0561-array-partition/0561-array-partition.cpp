class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int output = 0;
        for(int i = 0;i < nums.size() - 1; i++){
            output += min(nums[i],nums[i+1]);
            i++;
        }
        return output;
    }
};