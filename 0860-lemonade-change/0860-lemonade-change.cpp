class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_dollar= 0, ten_dollar = 0;

        for(auto&bill:bills){
            if(bill == 5) five_dollar++;
            else if(bill == 10){
                if(five_dollar == 0) return false;
                five_dollar--,ten_dollar++;
            }else{
                if(five_dollar > 0 && ten_dollar > 0){
                    five_dollar-- , ten_dollar--;
                }else if(five_dollar >=3 ) five_dollar-=3;
                else return false;
            }
        }
        return true;

    }
};