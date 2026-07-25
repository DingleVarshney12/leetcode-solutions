/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void extractAllPaths(TreeNode* root,string path,vector<string>& ans){
        if(!root) return;
        path += to_string(root->val);
        if(!root->left && !root->right){
             ans.push_back(path);
            return;
        }
        path += "->";
        extractAllPaths(root->left,path,ans);
        extractAllPaths(root->right,path,ans);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path = "";
        extractAllPaths(root,path,ans);
        return ans;
    }
};