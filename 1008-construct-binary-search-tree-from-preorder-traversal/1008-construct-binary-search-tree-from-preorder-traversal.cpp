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
    TreeNode* insert(TreeNode* root,int key){
        if(root == nullptr) {
            return new TreeNode(key);
        }
        if(key < root->val){
            root->left = insert(root->left,key);
        }else{
            root->right = insert(root->right,key);
        }
        return root;
    }
    TreeNode* build(const vector<int>& preorder){
        TreeNode* root = nullptr;
        for(auto x:preorder){
            root = insert(root,x);
        }    
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder);
    }
};