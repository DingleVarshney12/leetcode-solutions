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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        for(int i = 0 ;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1] < b[1];
        });
        Trie t;
        int i = 0;
        vector<int> ans(queries.size());

        for(auto &q : queries){

            int x = q[0], m = q[1],index = q[2];
            while(i < nums.size() && nums[i] <= m){
                t.insert(nums[i]);
                i++;
            }
            ans[index] = (i==0) ? -1 :  t.maxXOR(x);
        }
        return ans;
    }
};