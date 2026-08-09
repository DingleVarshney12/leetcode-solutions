struct TrieNode{
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(){
        isEndOfWord = false;
        for(int i = 0; i < 26;i++){
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
TrieNode* root= nullptr;


bool dfs(TrieNode* curr,int index,string& word){
    if(index == word.size()){
        return curr->isEndOfWord;
    }
    if(word[index] == '.'){
        for(int i = 0; i<26;i++){
            if(curr->children[i] != nullptr){
                if(dfs(curr->children[i],index+1,word)){
                    return true;
                }
            }
        } 
        return false;
    }
    int idx = word[index] - 'a';
    if(!curr->children[idx]) return false;
    return dfs(curr->children[idx],index+1,word);
}
public:
    WordDictionary() {
        root= new TrieNode(); 
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char ch : word){
            int index = ch - 'a';
            if(curr->children[index] == nullptr){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return dfs(root,0,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */