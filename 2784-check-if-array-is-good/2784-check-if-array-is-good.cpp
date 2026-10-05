class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> freq(201,0);
        for(auto&num:nums){
            freq[num]++;
            if(freq[num] == 2 && num != n) return false;
        }
        for(int i = 1;i < n;i++){
            if(freq[i] != 1) return false;
        }
        return freq[n] == 2;

    }
};