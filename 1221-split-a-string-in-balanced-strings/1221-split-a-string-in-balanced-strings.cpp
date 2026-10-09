class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0,count=0;
        for(auto&c:s){
            if(c == 'R') balance+=1;
            else if(c == 'L') balance-=1;
            if(balance==0) count++;
        }
        return count;
    }
};