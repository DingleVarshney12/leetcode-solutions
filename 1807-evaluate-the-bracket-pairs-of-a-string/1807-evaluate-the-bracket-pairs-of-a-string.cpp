class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> database;
        database.reserve(knowledge.size());

        for (const auto& k : knowledge) {
            database[k[0]] = k[1];
        }

        string output;
        output.reserve(s.size());

        int i = 0;

        while (i < s.size()) {
            if (s[i] == '(') {
                ++i;

                string key;
                while (s[i] != ')') {
                    key += s[i++];
                }

                auto it = database.find(key);

                if (it != database.end())
                    output += it->second;
                else
                    output += '?';

                ++i;
            } else {
                output += s[i++];
            }
        }

        return output;
    }
};
