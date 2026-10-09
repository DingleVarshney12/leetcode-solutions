class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums,
                                    vector<vector<int>>& queries) {
        int sum = accumulate(begin(nums), end(nums), 0, [](int s, int a) {
            return s + (a % 2 == 0 ? a : 0);
        });
        vector<int> output;
        for (auto& query : queries) {
            int index = query[1];

            //remove old value
            if (nums[index] % 2 == 0)
                sum -= nums[index];

            nums[index] += query[0];

            // add new value 
            if (nums[index] % 2 == 0)
                sum += nums[index];

            output.push_back(sum);
        }
        return output;
    }
};