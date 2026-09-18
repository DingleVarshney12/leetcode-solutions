class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefixSum = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i =0 ;i < nums.size();i++){
            if(nums[i] == 0) prefixSum--;
            else prefixSum++;

            if(mp.count(prefixSum)){
                maxLen = max(maxLen,i - mp[prefixSum]);
            }else mp[prefixSum] = i; 
        }
        return maxLen;
    }
};