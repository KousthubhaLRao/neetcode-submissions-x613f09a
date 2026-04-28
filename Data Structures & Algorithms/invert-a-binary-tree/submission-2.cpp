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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode *> stak;
        TreeNode *cur = root;
        if(root) stak.push(cur);
        while(!stak.empty())
        {
            cur = stak.top(); stak.pop();
            swap(cur->left, cur->right);
            if(cur->left) stak.push(cur->left);
            if(cur->right) stak.push(cur->right);
        }
        return root;
    }
};
