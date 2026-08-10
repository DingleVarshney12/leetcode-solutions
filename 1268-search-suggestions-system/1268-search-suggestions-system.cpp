struct TrieNode{
    TrieNode* children[26];
    vector<string> products;
    TrieNode(){
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
    void insert(vector<string>& products){
        for(auto& product:products){
            TrieNode* curr = root;
            for(char ch:product){
                int index = ch - 'a';
                if(!curr->children[index]){
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
                if(curr->products.size() < 3){
                    curr->products.push_back(product);
                }
            }
        }
    }
    vector<vector<string>> search(string searchWord){
        vector<vector<string>> result;
        TrieNode* curr = root;
        bool found = true;
        for(char ch:searchWord){
            if(!found){
                result.push_back({});
                continue;
            }
            int index = ch - 'a';
            if(!curr->children[index]){
                found = false;
                result.push_back({});
                continue;
            }
            curr = curr->children[index];
            result.push_back(curr->products);
        }
        return result;
    }
};
class Solution {

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        Trie t;
        t.insert(products);
        vector<vector<string>> result = t.search(searchWord);
        return result;
    }
};