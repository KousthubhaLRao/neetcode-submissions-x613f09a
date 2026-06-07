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
    bool isValidBST(TreeNode* root) {
        //well it wasn't bfs, it's dfs.
        return valid(root, INT_MIN, INT_MAX);
    }

    bool valid(TreeNode *node, int left, int right)
    {
        if(!node) return true;

        if(!(left < node->val and node->val < right)) return false;

        return valid(node->left, left, node->val) and valid(node->right, node->val, right); //right so here, node->val is passed so that the next node is compared against its parent's value to make sure.
    }
};
