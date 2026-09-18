class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};

        vector<vector<int>> output;
        sort(intervals.begin(), intervals.end());

        vector<int> curr = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= curr[1]) {
                curr[1] = max(curr[1], intervals[i][1]);
            } else {
                output.push_back(curr);
                curr = intervals[i];
            }
        }

        output.push_back(curr);

        return output;
    }
};