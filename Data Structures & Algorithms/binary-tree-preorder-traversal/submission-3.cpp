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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        while(root)
        {
            if(!root->left) //if no left child
            {
                res.emplace_back(root->val);
                root = root->right;
            }
            else
            {
                TreeNode *pred = root->left; //the inorder predecessor
                while(pred->right and pred->right != root)
                {
                    pred = pred->right;
                }
                if(!pred->right) //this means the "root" node is being visited for the first time. (not the actual root)
                {
                    res.emplace_back(root->val);
                    pred->right = root;
                    root = root->left;
                }
                else //thread already exists. We are returning after finishing the left subtree
                {
                    pred->right = nullptr;
                    root = root->right;
                }
            }
        }
        return res;
    }
};