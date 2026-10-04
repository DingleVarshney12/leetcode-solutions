class Solution {
    bool isVowel(char ch){
        return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch =='u') || (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U');
    }
public:
    string toGoatLatin(string sentence) {
        string output;
        stringstream ss(sentence);
        string word;
        string addA = "a";
        while(ss >> word){
            if(!output.empty()) output += " ";
            if(isVowel(word[0])){
                output += word + "ma";
            }else{
                output += word.substr(1) + word[0] + "ma";
            }
            output += addA;
            addA += 'a';
        }
        return output;
    }
};