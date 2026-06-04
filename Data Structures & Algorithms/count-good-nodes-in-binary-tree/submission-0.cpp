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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        //my thinking is to go depth first, and if the value at a node is greater than the current greatest element till that iteration, then i'll increment the number of such nodes.
        int count = 0;
        int max = root->val;
        dfs(root, count, max);

        return count;
    }

    void dfs(TreeNode *node, int &count, int maxim)
    {
        if(!node) return;

        if(node->val >= maxim)
        {
            maxim = node->val;
            count++;
        }

        dfs(node->left, count, maxim);
        dfs(node->right, count, maxim);
    }
};
