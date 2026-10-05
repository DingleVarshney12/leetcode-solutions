class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0;
        int digits[4];

        for (int i = 0; i < 4; i++) {
            digits[i] = min({num1 % 10, num2 % 10, num3 % 10});
            num1 /= 10, num2 /= 10, num3 /= 10;
        }

        for (int i = 3; i >= 0; i--) {
            ans = ans * 10 + digits[i];
        }

        return ans;
    }
};
