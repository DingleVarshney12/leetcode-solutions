class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        unsigned int mask = static_cast<unsigned int>(x);
        mask &= -mask;
        int unique1 = 0 , unique2 = 0;
        for(auto&num:nums){
            if(num & mask){
                unique1 ^= num;
            }else{
                unique2 ^=num;
            }
        }
        return {unique1,unique2};
    }
};