class Solution {
public:
    string removeOuterParentheses(string s) {
        string output;
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                if (balance > 0)
                    output += c;
                balance++;
            } else {
                balance--;
                if (balance > 0)
                    output += c;
            }
        }

        return output;
    }
};