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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        long long maxWidth =1;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long firstIdx= q.front().second;
            long long lastIdx;
            for(int i = 0;i<size;i++){
                auto [node,idx] = q.front();
                q.pop();
                lastIdx = idx;
                idx = idx - firstIdx;
                if(node->left) q.push({node->left,2*idx +1});
                if(node->right) q.push({node->right,2*idx+2});
            }
            long long width = lastIdx - firstIdx + 1;
            maxWidth = max(maxWidth,width);
        }
        return maxWidth;
    }
};