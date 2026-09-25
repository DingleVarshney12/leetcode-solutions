// Approach inspired by another LeetCode solution:
// Aura Farming

class Solution {
    void dfs(string expression,set<string>&s){
        int r = expression.find('}');
        if(r == string::npos){
            s.insert(expression);
            return;
        }
        int l = expression.rfind('{',r);  
        string left = expression.substr(0,l);
        string right =expression.substr(r+1);
        string inner = expression.substr(l+1,r-l-1);
        string part;
        stringstream ss(inner);
        while(getline(ss,part,',')){
            dfs(left+part+right,s);
        }

    } 
public:
    vector<string> braceExpansionII(string expression) {
        set<string> s;
        dfs(expression,s);
        return vector<string>(s.begin(),s.end());
    }
};