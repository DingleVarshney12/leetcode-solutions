class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {

            if (a.first == b.first)
                return a.second > b.second;

            return a.first < b.first;
        }
    };

    vector<int> topStudents(vector<string>& positive_feedback,
                            vector<string>& negative_feedback,
                            vector<string>& report, vector<int>& student_id,
                            int k) {

        unordered_set<string> pos(positive_feedback.begin(),
                                  positive_feedback.end());

        unordered_set<string> neg(negative_feedback.begin(),
                                  negative_feedback.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (int i = 0; i < student_id.size(); i++) {

            int score = 0;
            istringstream iss(report[i]);
            string word;

            while (iss >> word) {
                if (pos.count(word))
                    score += 3;

                if (neg.count(word))
                    score -= 1;
            }

            pq.push({score, student_id[i]});
        }

        vector<int> ans;

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
