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
    void inorder(TreeNode* root,vector<int>& arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

    TreeNode* build(const vector<int>& arr,int left,int right){
        if(left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = build(arr,left,mid-1);
        node->right = build(arr,mid+1,right);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return nullptr;
        vector<int> arr;
        inorder(root,arr);
        int left = 0;
        int right = arr.size()-1;
        
        return build(arr,left,right);
    }
};