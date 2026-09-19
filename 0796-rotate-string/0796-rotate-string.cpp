class Solution {
public:
    bool rotateString(string s, string goal) {
        string check = goal + goal;
        if(check.contains(s)){
            return true;
        }
        return false;
    }
};