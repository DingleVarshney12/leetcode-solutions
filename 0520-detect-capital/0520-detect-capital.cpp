class Solution {

public:
    bool detectCapitalUse(string word) {
        int count = 0;

        for(char&ch:word){
            if(isupper(ch)) count++;
        }
        if(count == 1 && isupper(word[0])) return true;
        else if(count == 0 || count == word.size()) return true;
        else return false; 
    }
};