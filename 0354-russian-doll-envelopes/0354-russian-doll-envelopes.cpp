class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int ans = 0;
        vector<int> tails;
        for(auto env: envelopes){
            int height = env[1];
            auto it = lower_bound(tails.begin(), tails.end(), height);
            if(it == tails.end()){
                tails.push_back(height);
            }
            else{
                *it = height;
            }
        }
        return tails.size();
    }
};