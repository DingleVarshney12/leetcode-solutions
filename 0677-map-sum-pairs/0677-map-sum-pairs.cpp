struct TrieNode{
    int sum;
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(){
        sum = 0;
        for(int i = 0;i< 26;i++){
            children[i] = nullptr;
        }
    }
};

class MapSum {
    unordered_map<string,int> mp;
    TrieNode* root = nullptr;
public:
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        TrieNode* curr = root;
        int oldValue = mp[key];
        int delta = val - oldValue;
        for(char ch:key){
            int index = ch - 'a';
            if(!curr->children[index]){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->sum += delta;
        }
        mp[key] = val;
    }
    
    int sum(string prefix) {
        TrieNode* curr = root;
        for(char ch:prefix){
            int index = ch - 'a';
            if(!curr->children[index]) return 0;
            curr = curr->children[index];
        }
        return curr->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */