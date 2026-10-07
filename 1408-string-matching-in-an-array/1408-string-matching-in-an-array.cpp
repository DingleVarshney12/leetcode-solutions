class Solution {
public:
    vector<int> buildLPS(string& pattern) {
        int m = pattern.size();

        vector<int> lps(m, 0);

        int len = 0, i = 1;

        while (i < m) {

            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    bool KMP(string& text, string& pattern) {

        int n = text.size(), m = pattern.size();

        if (m > n)
            return false;

        vector<int> lps = buildLPS(pattern);

        int i = 0, j = 0;
        
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return true;
            }
            else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (KMP(words[j], words[i])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};