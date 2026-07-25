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
    bool solve(TreeNode* root, int targetSum){
        if(root == nullptr) return false;
        if(!root->left && !root->right){
            if(targetSum - root->val == 0){
                return true;
            }
        }
       int remaining = targetSum - root->val;
        return solve(root->left,remaining) || solve(root->right,remaining);

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum);
    }
};