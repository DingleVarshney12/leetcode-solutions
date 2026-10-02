class Solution {
    vector<string> output;
    void backtrack(int open,int close,string curr,int n){
        if(open == n && close == n){
            output.push_back(curr);
        }
        if(open < n){
            backtrack(open + 1,close,curr+ '(',n);
        }
        if(close < open){
            backtrack(open,close + 1 ,curr + ')',n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        backtrack(0,0,"",n);
        return output;    
    }
};