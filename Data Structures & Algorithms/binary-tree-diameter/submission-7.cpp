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
    int diameterOfBinaryTree(TreeNode* root) {
        stack<TreeNode *> stak;
        unordered_map<TreeNode *, pair<int, int>> mp;  //map stores height and diameter for each visited node.
        mp[nullptr] = {0, 0}; //we get 0,0 whenever we try to access null children of any node
        stak.push(root);

        while(!stak.empty())
        {
            TreeNode *node = stak.top();

            if(node->left and !mp.count(node->left)) stak.push(node->left);  //if node has a valid left child and the left child is being visited for the first time, push it into the stack. 
            else if(node->right and !mp.count(node->right)) stak.push(node->right); //same thing, but for right child.
            else
            {
                node = stak.top();
                stak.pop();  //the pop happens for nodes when they've been visited completely.

                auto[leftHeight, leftDia] = mp[node->left];
                auto[rightHeight, rightDia] = mp[node->right];

                int height = 1 + max(leftHeight, rightHeight);
                int dia = max(leftHeight + rightHeight, max(leftDia, rightDia));

                mp[node] = {height, dia};
            }
        }
        return mp[root].second;
    }
};
