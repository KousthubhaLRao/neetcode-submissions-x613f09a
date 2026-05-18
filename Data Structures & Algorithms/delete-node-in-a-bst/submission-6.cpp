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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        TreeNode *parent = nullptr; //it is important to initialise as nullptr in case the node to be deleted is the root node itself
        TreeNode *cur = root;

        while(cur and cur->val != key)
        {
            parent = cur;
            if(key < cur->val) cur = parent->left;
            else cur = parent->right;
        }

        if(!cur) return root;

        if(!cur->left or !cur->right) //0 children or 1 child
        {
            TreeNode *child = cur->left ? cur->left : cur->right;  //if left child exists, assign left child. else right.

            if(!parent) return child; //this is for the root node i believe
            
            if(parent->left == cur) parent->left = child; //gives the child to the grandparent based on where the deleted node was.
            else parent->right = child;
        }
        else //2 childrem
        {
            TreeNode *par = nullptr; //this'll be used to point to the parent of the inorder successor (leftmost node in right subtree)
            TreeNode *delNode = cur;  //it is the node to be deleted
            
            cur = cur->right;
            while(cur->left)  //finding the inorder successor 
            {
                par = cur;
                cur = cur->left;
            }

            if(par) //if there was a left traversal. (i.e, the while loop above ran at leaset once)
            {
                par->left = cur->right;
                cur->right = delNode->right;
            }
            cur->left = delNode->left;
            
            if(!parent) return cur; //if root is being deleted

            if(parent->left == delNode) parent->left = cur;
            else parent->right = cur;  //the actual replacement of the to-be-deleted node with the inorder successor
        }
        return root;
    }
};