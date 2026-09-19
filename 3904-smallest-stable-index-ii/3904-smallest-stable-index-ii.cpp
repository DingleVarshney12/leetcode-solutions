class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n) , suffixSum(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n;i++){
            prefixSum[i] = max(prefixSum[i-1],nums[i]);
        }
        suffixSum[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0;i--){
            suffixSum[i] = min(suffixSum[i+1],nums[i]);
        }
        for(int i = 0 ;i < n;i++){
            if((prefixSum[i] - suffixSum[i]) <= k) return i;
        }
        return -1;
    }
};