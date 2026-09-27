class Solution {
    string dfs(string s){
        int r = s.find(')');
        if(r == string::npos){
            return s;
        }
        int l = s.rfind('(',r);
        string left = s.substr(0,l);
        string right = s.substr(r+1);
        string content = s.substr(l+1,r-l-1);
        reverse(begin(content),end(content));
        return dfs(left+content+right);
    }
public:
    string reverseParentheses(string s) {
        return dfs(s);
    }
};