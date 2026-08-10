struct TrieNode{
    bool isEndOfWord;
    TrieNode* children[26];
    TrieNode(){
        isEndOfWord = false;
        for(int i = 0;i<26;i++){
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
        for(char ch:word){
            int index = ch - 'a';
            if(!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    bool isValidWord(string word){
        TrieNode* curr = root;
        for(char ch:word){
            int index = ch -'a';
            if(!curr->children[index]) return false;
            curr = curr->children[index];
            if(!curr->isEndOfWord) return false;
        }
        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t;
        for(auto &word:words){
            t.insert(word);
        }
        string ans = "";
        for(auto &word:words){
            if(t.isValidWord(word)){
                if(word.length() > ans.length() || (word.length() == ans.length() && word < ans)){
                    ans = word;
                }
            }
        }
        return ans;
    }
};