class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
            return 1;

        int bitLength = log2(num) + 1;

        unsigned int mask = (1U << bitLength) - 1;

        return num ^ mask;
    }
};