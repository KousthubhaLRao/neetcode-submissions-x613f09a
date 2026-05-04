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
    bool sameTree(TreeNode *root1, TreeNode *root2)
    {
        if(!root1 and !root2) return true;
        else if(root1 and root2 and root1->val == root2->val) return sameTree(root1->left, root2->left) and sameTree(root1->right, root2->right);
        else return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true; //empty tree is a subtree by default
        if(!root) return false; //empty tree can't have any subtrees other than empty tree

        if(sameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};
