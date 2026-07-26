/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string serialized="";
    void serializeTree(TreeNode*root){
        if(!root){
            serialized += "null,";
            return;
        }
        serialized += to_string(root->val);
        serialized += ",";
        serializeTree(root->left);
        serializeTree(root->right);
    }
    vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(str);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    TreeNode* deserilizeString(vector<string>& tokens,int& idx){
        if(tokens[idx] == "null"){
            idx++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(tokens[idx]));
        idx++;
        node->left = deserilizeString(tokens,idx);
        node->right = deserilizeString(tokens,idx);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        serialized ="";
        serializeTree(root);
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens = split(data,',');
        int idx = 0;
       return  deserilizeString(tokens,idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));