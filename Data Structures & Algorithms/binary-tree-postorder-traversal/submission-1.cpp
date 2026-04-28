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
class Solution {  //I DO NOT UNDERSTAND MORRIS TRAVERSAL VERY WELL, MUST REVISIT.
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root;
        while(cur)
        {
            if(!cur->right)
            {
                res.emplace_back(cur->val);
                cur = cur->left;
            }
            else
            {
                TreeNode *succ = cur->right; //inorder successor
                while(succ->left and succ->left != cur)
                {
                    succ = succ->left;
                }
                if(!succ->left)
                {
                    res.emplace_back(cur->val);
                    succ->left = cur;
                    cur = cur->right;
                }
                else
                {
                    succ->left = nullptr;
                    cur = cur->left;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};