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
    int dfs(TreeNode *cur, bool &isBal)
    {
        if(!cur) return 0;
        int left = dfs(cur->left, isBal);
        int right = dfs(cur->right, isBal);

        if(abs(left-right) > 1) isBal = false;
        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool isBal = true;
        dfs(root, isBal);
        return isBal;
    }
};
