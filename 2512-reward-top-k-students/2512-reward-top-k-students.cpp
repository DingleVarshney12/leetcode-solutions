class Solution {
public:
    /**
    * Compare score, and if same then compare student_id.
    * Worst student stays at the top.
    */
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {

            if (a.first != b.first)
                return a.first > b.first; 
 
            return a.second < b.second;
        }
    };

    vector<int> topStudents(vector<string>& positive_feedback,
                            vector<string>& negative_feedback,
                            vector<string>& report, vector<int>& student_id,
                            int k) {

        /**
        * Hash Set for fast Looks Up 
        */
        unordered_set<string> pos(positive_feedback.begin(),
                                  positive_feedback.end());

        unordered_set<string> neg(negative_feedback.begin(),
                                  negative_feedback.end());


        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (int i = 0; i < student_id.size(); i++) {

            int score = 0;
            // split string by space
            istringstream iss(report[i]);
            string word;

            while (iss >> word) {
                if (pos.count(word))
                    score += 3;

                if (neg.count(word))
                    score -= 1;
            }

            pq.push({score, student_id[i]});

            // fixed k size priority queue 
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
