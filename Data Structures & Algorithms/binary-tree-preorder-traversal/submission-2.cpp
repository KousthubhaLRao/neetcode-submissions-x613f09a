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
                stak.push(root->right); //there's no problem in pushing even a nullptr, because the code to add its value to res is locked behind the if(root) statement and in a previous iteration, when root = stack.top() executres, root becomes nullptr, but its value won't be dereferenced because of the if(root) statement.
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