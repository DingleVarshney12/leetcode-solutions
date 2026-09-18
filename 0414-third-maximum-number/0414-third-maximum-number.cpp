class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long firstMaximum = LONG_MIN,secondMaximum = firstMaximum,thirdMaximum = secondMaximum;

        for(auto&num:nums){
            if( firstMaximum < num){
                thirdMaximum = secondMaximum;
                secondMaximum = firstMaximum;
                firstMaximum = num;
            }else if(secondMaximum < num && num != firstMaximum){
                thirdMaximum= secondMaximum;
                secondMaximum = num;
            }else if(thirdMaximum < num && num !=secondMaximum && num != firstMaximum){
                thirdMaximum = num;
            }
        }
        return thirdMaximum == LONG_MIN ? firstMaximum : thirdMaximum;
    }
};