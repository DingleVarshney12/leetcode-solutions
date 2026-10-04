class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_codes = {
            ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
            "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
            "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
            "...-", ".--",  "-..-", "-.--", "--.."
        };
        unordered_set<string> s;

        for(auto& word:words){
            string morse_code;
            for(int i = 0; i < word.size();i++){
                int index = word[i] - 'a';
                string code = morse_codes[index];
                morse_code+=code; 
            }
            s.insert(morse_code);
        }
        return s.size();
    }
};