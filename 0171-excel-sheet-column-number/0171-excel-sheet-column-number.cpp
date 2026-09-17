class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long output = 0;
        for(int i =0;i<columnTitle.length();i++){
            output *= 26;
            output += (columnTitle[i] - 'A' + 1);
        }
        return (int)output;
    }
};