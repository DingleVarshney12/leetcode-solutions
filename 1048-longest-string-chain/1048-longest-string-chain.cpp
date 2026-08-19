class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.length() < b.length(); });
        int ans = 1;
        unordered_map<string, int> dp;
        for (auto word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.length(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(predecessor) != dp.end()) {
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }
            ans = max(ans, dp[word]);
        }

        return ans;
    }
};