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
int preorderIdx = 0;
TreeNode* build(vector<int>& preorder,vector<int>& inorder, int start,int end,unordered_map<int,int>& mp){
    if(start > end) return nullptr;
    TreeNode* root = new TreeNode(preorder[preorderIdx++]);
    int rootIdx = mp[root->val];
    root->left = build(preorder,inorder,start,rootIdx-1,mp);
    root->right = build(preorder,inorder,rootIdx +1,end,mp);
    return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i = 0;i < inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return build(preorder,inorder,0,inorder.size()-1,mp);
    }
};