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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *cur = root;

        while(cur)
        {
            if(!cur->left) //if cur has no left child
            {
                res.emplace_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode *ino_pred = cur->left;
                while(ino_pred->right and ino_pred->right != cur)
                {
                    ino_pred = ino_pred->right;
                }
                if(!ino_pred->right)
                {
                    ino_pred->right = cur;
                    cur = cur->left;
                }
                else
                {
                    ino_pred->right = nullptr;
                    res.emplace_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};