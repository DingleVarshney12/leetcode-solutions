class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int output = 0;
        for(int&num:nums){
            output = gcd(output,num);
            if(output == 1) return true;
        }
        return false;
    }
};