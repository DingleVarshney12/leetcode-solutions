class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1, right = n;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long required_coins = mid * (mid + 1) / 2;

            if (required_coins == n) {
                return mid;
            } else if (required_coins < n)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};