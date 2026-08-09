struct TrieNode{
    TrieNode* children[26];
    string word;
    TrieNode(){
        word = "";
        for(int i = 0; i < 26;i++){
            children[i] = nullptr;
        }
    }
};
  

class Solution {
    const int dr[4] = {0,1,0,-1};
    const int dc[4] = {1,0,-1,0};
public:
    TrieNode* root= new TrieNode;
    // insert word into trie
    void insert(string word){
        TrieNode* curr = root;
        for(char ch : word){
            int index = ch - 'a';
            if(curr->children[index] == nullptr){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->word = word;
    }
    void dfs(int row,int col,TrieNode*curr,vector<vector<char>>&board,vector<string>&ans){
        //boundary +visited check
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col] == '#'){
            return;
        }
        //current character
        char ch = board[row][col];
        int index = ch - 'a';
        // no matching trie path
        if(!curr->children[index]) return;
        //move to next trie node
        curr = curr->children[index];
        
        //found word
        if(curr->word != ""){
            ans.push_back(curr->word);
            //avoid duplicates
            curr->word = "";
        }
        //mark current cell as visited
        board[row][col] = '#';
        
        for(int k = 0;k<4;k++){
            dfs(row + dr[k],col+dc[k],curr,board,ans);
        }
        //backtrack
        board[row][col] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //build trie
        for(string word:words){
            insert(word);
        }
        vector<string> ans;
        int m = board.size();
        int n = board[0].size();
        //start dfs
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                dfs(i,j,root,board,ans);
            }
        }
        return ans;
    }
};