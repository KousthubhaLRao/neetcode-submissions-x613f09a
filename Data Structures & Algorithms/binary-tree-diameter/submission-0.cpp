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
    int max_dia = 0;
    int maxDepth(TreeNode *root)
    {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int dia = maxDepth(root->left) + maxDepth(root->right);  //diameter at a specific node.
        max_dia = max(max_dia, dia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return max_dia;
    }
};
