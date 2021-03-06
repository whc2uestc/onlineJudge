/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(NULL == root)
            return root;
        TreeNode *pNode = root->left;
        root->left = root->right;
        root->right = pNode;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};