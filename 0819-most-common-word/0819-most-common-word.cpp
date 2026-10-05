class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> freq;
        unordered_set<string> banned_words(begin(banned),end(banned));
        for(auto&ch:paragraph){
            ch = isalpha(ch) ? tolower(ch) : ' '; 
        }
        stringstream ss(paragraph);
        string word;
        pair<string,int> output("",0);
        while(ss >> word){
            if(banned_words.count(word) < 1 && ++freq[word] > output.second)
                output = make_pair(word,freq[word]);
        }
        return output.first;
    }
};