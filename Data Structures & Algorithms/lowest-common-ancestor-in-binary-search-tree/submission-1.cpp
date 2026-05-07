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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        
        if(p->val < root->val and q->val < root->val) return lowestCommonAncestor(root->left, p, q); //smarter way is to use max(p, q)

        else if(p->val > root->val and q->val > root->val) return lowestCommonAncestor(root->right, p, q); //smarter way is to use min(p, q)

        else return root;
    }
};
