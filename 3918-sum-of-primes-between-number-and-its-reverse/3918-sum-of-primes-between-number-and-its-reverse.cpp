class Solution {
    int reverse(int n){
        int reversed=0;
        while(n){
            reversed = (reversed * 10) + (n % 10);
            n /= 10;
        }
        return reversed;
    }
    bool isPrime(int n){
        if(n<=1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        for(int i = 3; i <= sqrt(n);i+=2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
public:
    int sumOfPrimesInRange(int n) {
        int r = reverse(n);
        int minVal = min(n,r);
        int maxVal = max(n,r);
        int sum = 0;

        for(int i = minVal; i <= maxVal;i++ ){
            if(isPrime(i)){
                sum += i;
            }
        }
        return sum;
    }
};