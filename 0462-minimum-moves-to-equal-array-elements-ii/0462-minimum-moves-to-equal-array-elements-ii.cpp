class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int target = nums[n/2];
        int moves = 0;
        for(int& num:nums){
            moves += abs(target - num);
        }
        return moves;
    }
};