class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto& num:nums) freq[num]++;
        unordered_set<int> unique;
        for(auto [_,val]: freq) unique.insert(val);
        return freq.size() == unique.size();
    }
};