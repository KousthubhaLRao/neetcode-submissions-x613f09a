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
    int pre_idx = 0;
    unordered_map<int, int> indices;

    TreeNode *dfs(vector<int> &preorder, int l, int r)
    {
        if(l > r) return nullptr;  //this gets triggered when we hit leaf nodes
        int root_val = preorder[pre_idx++];  //every parent node is taken from left to right in the preorder traversal

        TreeNode *root = new TreeNode(root_val);  //create a new parent node with root_val.
        int mid = indices[root_val]; //this gets us the index of the current parent node from the inorder traversal's hashmap, so that we can split the inorder traversal into left and right halves
        root->left = dfs(preorder, l, mid-1);
        root->right = dfs(preorder, mid+1, r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            indices[inorder[i]] = i;  //hashmap is built here to map every value to its inorder index

        return dfs(preorder, 0, inorder.size()-1);    
    }
};
