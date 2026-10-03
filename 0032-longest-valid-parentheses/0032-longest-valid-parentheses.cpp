class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), output = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < n; i++){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else output = max(output,i - st.top());
            }
        }
        return output;
    }
};