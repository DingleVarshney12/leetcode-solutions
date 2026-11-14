class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minimum_sum = INT_MAX;
        int i = 0, j = 0;
        int s = 0;
        while(j < n){
            int subarray_size = j - i + 1;
            if(subarray_size > r){
                i++;
                j = i;
                s = 0;
                continue;
            }
            s +=  nums[j++];
            if(s > 0 && subarray_size >= l){
                minimum_sum = min(minimum_sum,s);
            }
            if(j == n){
                i++;
                j = i;
                s = 0;
            }
        }
        return minimum_sum == INT_MAX ? -1 : minimum_sum;
    }
};