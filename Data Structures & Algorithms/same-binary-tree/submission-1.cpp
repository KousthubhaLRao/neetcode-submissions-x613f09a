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
    bool isSameTree(TreeNode* p, TreeNode* q) { //bfs with queue
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);

        while(!q1.empty() and !q2.empty())
        {
            TreeNode *node1 = q1.front(); q1.pop();
            TreeNode *node2 = q2.front(); q2.pop();

            if(!node1 and !node2) continue;
            else if(node1 and node2 and node1->val == node2->val)
            {
                q1.push(node1->left); q1.push(node1->right);
                q2.push(node2->left); q2.push(node2->right);
            } 
            else return false; //if only one node is null, or the values don't match
        }
        return true;
    }
};
