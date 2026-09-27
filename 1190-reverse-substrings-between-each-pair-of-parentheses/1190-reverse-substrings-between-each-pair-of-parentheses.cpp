class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        vector<int> pair(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                int j = st.top();
                st.pop();

                pair[i] = j;
                pair[j] = i;
            }
        }

        string ans;
        int i = 0;
        int direction = 1;

        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                direction = -direction;
            }
            else {
                ans += s[i];
            }

            i += direction;
        }

        return ans;
    }
};
