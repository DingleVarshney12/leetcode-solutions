class Solution {
public:
    string convertToTitle(int columnNumber) {
        string output;
        while(columnNumber){
            columnNumber--;
            output = (char)((columnNumber % 26) + 'A' ) + output;
            columnNumber/=26;
        }   
        return output;
    }
};