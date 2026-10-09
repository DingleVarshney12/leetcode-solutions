class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> freq;
        stringstream ss1(s1) , ss2(s2);
        string word;
        while(ss1 >> word){
           freq[word]++;
        }
        while(ss2 >>word){
            freq[word]++;
        }
        vector<string> output;
        for(auto& f: freq){
            if(f.second == 1) output.push_back(f.first);
        }
        return output;

    }
};