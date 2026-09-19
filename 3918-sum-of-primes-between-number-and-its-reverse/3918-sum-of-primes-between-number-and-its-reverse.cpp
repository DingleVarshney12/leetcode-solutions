class Solution {
    int reverse(int n) {
        int reversed = 0;
        while (n > 0) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }
        return reversed;
    }

public:
    int sumOfPrimesInRange(int n) {
        int r = reverse(n);

        int minVal = min(n, r);
        int maxVal = max(n, r);

        vector<bool> isPrime(maxVal + 1, true);

        if (maxVal >= 0) isPrime[0] = false;
        if (maxVal >= 1) isPrime[1] = false;

        for (int i = 2; i * i <= maxVal; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxVal; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int sum = 0;

        for (int i = minVal; i <= maxVal; i++) {
            if (isPrime[i]) {
                sum += i;
            }
        }

        return sum;
    }
};
