struct TrieNode {
    TrieNode* children[2];

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};
class Trie{
    TrieNode* root = nullptr;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        TrieNode* curr = root;
        for(int i = 30 ; i >=0;i--){
            int bit = (num>>i) &1;
            if(!curr->children[bit]) {
                curr->children[bit] = new TrieNode();
            }
           curr =  curr->children[bit] ;
        }
    }
    int maxXOR(int num){
        TrieNode* curr = root;
        int ans = 0;
        for(int i = 30;i>=0;i--){
            int bit = (num>>i) & 1;
            int opposite = 1 - bit;
            if(curr->children[opposite]){
                ans |= (1 << i);
                curr = curr->children[opposite];
            }else{
                curr = curr->children[bit];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto&num:nums){
            t.insert(num);
        }
        int ans = 0;
        for(auto&num:nums){
            ans = max(ans,t.maxXOR(num));
        }
        return ans;
    }
};