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
            TreeNode *right = nullptr; //this'll be used to track the right pointer
            for(int i = 0; i < size; i++)
            {
                TreeNode *node = q.front(); q.pop();
                if(node)
                {
                    right = node;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(right) res.emplace_back(right->val); //this works cus in the last iteration of every for loop, 'right' ends up pointing to the last node in the level. Think about it.
        }
        return res;
    }
};
