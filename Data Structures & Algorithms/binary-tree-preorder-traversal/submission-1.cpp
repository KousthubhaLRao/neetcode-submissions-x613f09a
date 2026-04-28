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
        //TreeNode *cur = root;
        stack<TreeNode *> stak;
        while(root or !stak.empty())
        {
            if(root)
            {
                res.emplace_back(root->val);
                stak.push(root->right);
                root = root->left;
            }
            else
            {
                root = stak.top();
                stak.pop();
            }
        }
        return res;
    }
};