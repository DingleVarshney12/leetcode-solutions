class Solution {
    bool isSelfDividing(int num) {
        int n = num;
        int flag = true;
        while (num) {
            int rem = num % 10;
            if (rem == 0) {
                flag = false;
                break;
            }
            if (rem != 0 && n % rem != 0) {
                flag = false;
                break;
            }
            num /= 10;
        }
        return flag;
    }

public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> output;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                output.push_back(i);
            }
        }
        return output;
    }
};