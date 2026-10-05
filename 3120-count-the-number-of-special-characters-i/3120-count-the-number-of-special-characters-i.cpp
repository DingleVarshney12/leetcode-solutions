class Solution {

public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> setA, setB;
        int count = 0;
        for(auto&ch:word){
            islower(ch) ? setA.insert(ch) : setB.insert(tolower(ch));
        }
        for(auto&ch:setA){
            if(setB.count(ch) > 0){
                count++;
            }
        }
        return count;
    }
};