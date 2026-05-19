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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // NOTE :  DFS → stack behavior → recursion works beautifully
        //         BFS → queue behavior → iterative works beautifully
        vector<vector<int>> res;
        if(!root) return {};
        queue<TreeNode *> q;

        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++)
            {
                TreeNode *node = q.front(); q.pop();
                if(node)
                {
                    level.emplace_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(!level.empty()) res.emplace_back(level);
        }

        return res;
    }
};
