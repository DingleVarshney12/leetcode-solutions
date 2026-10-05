class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(const auto&num:nums){
            mp[num]++;
        }
        sort(begin(nums),end(nums),[&](int a,int b){
            if(mp[a] == mp[b]){
                return a > b;
            }
            return mp[a] < mp[b];
        });
        return nums;
    }
};