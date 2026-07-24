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
bool isMirror(TreeNode* left,TreeNode* right){
        if(!left && !right) return true;
        else if(!left || !right) return false;
        else if(left->val !=right->val) return false;
        else{
            return isMirror(left->left,right->right) && isMirror(left->right,right->left); 
        }
}
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};