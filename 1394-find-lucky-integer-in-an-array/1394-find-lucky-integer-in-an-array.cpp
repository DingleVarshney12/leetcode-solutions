class Solution {
public:
    int findLucky(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto& num : nums) {
            freq[num]++;
        }
        int largest = 0;
        for (auto& num : nums) {
            if (num > largest && freq[num] == num) {
                largest = num;
            }
        }
        return largest == 0 ? -1 : largest;
    }
};