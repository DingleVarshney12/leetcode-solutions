class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> freq1,freq2;
        for(auto&word:words1) freq1[word]++;
        for(auto&word:words2) freq2[word]++;
        int count = 0;
        for(auto&word:words1){
            if(freq1[word] == 1 && freq2[word] == 1) count++;
         }
        return count;
    }
};