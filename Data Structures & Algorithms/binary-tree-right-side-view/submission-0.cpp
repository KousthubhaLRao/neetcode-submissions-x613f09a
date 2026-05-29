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
    vector<int> rightSideView(TreeNode* root) {
        //we're again gonna use bfs cus the nodes visible from the right side are those that are the last node in any given level. So we need level by level traversal.
        vector<int> res;
        if(!root) return res;
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
            if(!level.empty()) res.emplace_back(level.back()); //cus the last node in the level is the only one that can be seen from the right.
        }
        return res;
    }
};
