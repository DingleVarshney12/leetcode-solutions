struct TrieNode{
    bool isEndOfWord;
    TrieNode* children[26];
    TrieNode(){
        isEndOfWord = false;
        for(int i =0;i<26;i++){
            children[i] = nullptr;
        }
    }
};

class Trie{
    TrieNode* root = nullptr;
public:
    Trie(){
        root = new TrieNode(); 
    }
    void insert(string word){
        TrieNode* curr = root;
        for(auto ch:word){
            int index = ch - 'a';
            if(!curr->children[index]) {
                curr->children[index] = new TrieNode();;
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    string replaceWord(string word){
        TrieNode* curr = root;
        string prefix ="";
        for(char ch :word){
            int index = ch - 'a';
            if(!curr->children[index]) return word;
            curr = curr->children[index];
            prefix += ch;
            if(curr->isEndOfWord) return prefix;
        }
        return word;
    }
};
class Solution {

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for(auto& word: dictionary){
            t.insert(word);
        }
        stringstream ss(sentence);
        string word, result;
        while(ss >> word){
            if(!result.empty()){
                result += " ";
            }
            result += t.replaceWord(word);
        }
        return result;
    }
};