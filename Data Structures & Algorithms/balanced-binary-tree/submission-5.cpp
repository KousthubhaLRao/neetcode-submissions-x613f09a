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

class Solution {  //I HAVE A DOUBT ABOUT THE DIFFERENCES BETWEEN THE CODE IN THE SOLUTION, AND MY CODE. APPARENTLY, 
public:
    bool isBalanced(TreeNode* root) {
        bool isBal = true;
        if(!root) return isBal;

        unordered_map<TreeNode *, int> mp;
        stack<TreeNode *> stak;
        stak.push(root);

        while(!stak.empty())
        {
            TreeNode *cur = stak.top();
            if(cur->left and !mp.count(cur->left)) stak.push(cur->left); //if left child is valid, and it's being visited the first time.
            else if(cur->right and !mp.count(cur->right)) stak.push(cur->right); //same for right.
            else
            {
                cur = stak.top(); stak.pop();

                int leftHeight = mp[cur->left];
                int rightHeight = mp[cur->right];

                if(abs(leftHeight - rightHeight) > 1) isBal = false;
                mp[cur] = 1 + max(leftHeight, rightHeight);
            }
        }
        return isBal;
    }
};
