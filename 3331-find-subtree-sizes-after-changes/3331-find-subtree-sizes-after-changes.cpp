
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) adj[parent[i]].push_back(i);

        vector<int> ans(n, 1);
        vector<int> last(26, -1);
        vector<int> prev(n, -1);

        stack<pair<int, int>> st;
        st.push({0, 0});

        while (!st.empty()) {
            auto [u, state] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (state == 0) {
                prev[u] = last[c];
                last[c] = u;

                st.push({u, 1});

                for (int v : adj[u]) st.push({v, 0});
            } else {
                last[c] = prev[u];

                int p = (prev[u] != -1) ? prev[u] : parent[u];

                if (p != -1) ans[p] += ans[u];
            }
        }

        return ans;
    }
};
