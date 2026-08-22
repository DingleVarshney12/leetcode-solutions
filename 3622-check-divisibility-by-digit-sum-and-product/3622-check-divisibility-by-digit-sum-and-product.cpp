class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0,prod=1;
        int num = n;
        while(num){
            int rem = n % 10;
            sum += rem;
            prod *= rem;
            num/=10;
        }
        return n % (sum+prod) == 0;
    }
};