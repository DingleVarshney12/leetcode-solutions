class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> freq;
        for (auto& res : responses) {
            unordered_set<string> seen;
            for (auto& word : res) {
                if (seen.insert(word).second) {
                    freq[word]++;
                }
            }
        }
        int maxi = INT_MIN;
        string maxRes = "";
        for (auto& f : freq) {
            if (f.second > maxi || (f.second == maxi && f.first < maxRes)) {
                maxi = f.second;
                maxRes = f.first;
            }
        }
        return maxRes;
    }
};