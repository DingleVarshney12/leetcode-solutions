class Solution {
#define f(i, a, n) for (int i = a; i < n; i++)

    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();
        vector<tuple<int, int, int>> digit_sums;

        f(i, 0, n) { digit_sums.push_back({digitSum(nums[i]), nums[i], i}); }

        sort(begin(digit_sums), end(digit_sums));
        
        vector<bool> visited(n, false);
        int swaps = 0;

        f(i, 0, n) {
            
            if (visited[i] || get<2>(digit_sums[i]) == i)
                continue;

            int j = i;
            int cycles = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = get<2>(digit_sums[j]);
                cycles++;
            }
            
            swaps += cycles - 1;
        
        }
        return swaps;
    }
};