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
    int kthSmallest(TreeNode* root, int k) {
        //GODDAMN MORRIS TRAVERSAL.

        TreeNode *cur = root;

        while(cur)
        {
            //case 1 : no left child
            if(!cur->left)
            {
                k--; //this is considered "visiting" the node
                if(k == 0) return cur->val;
                cur = cur->right;
            }
            else
            {
                TreeNode *pred = cur->left; //pred = inorder predecessor
                while(pred->right and pred->right != cur) pred = pred->right;  //ask a doubt about the pred->right != cur condition

                if(pred->right == nullptr)
                {
                    pred->right = cur;   //temporary thread creation
                    cur = cur->left;
                }

                else //thread already exists, i.e the current node has already been visited
                {
                    pred->right = nullptr;
                    k--; //this is considered "visiting" the node
                    if(k == 0) return cur->val;
                    cur = cur->right;
                }
            }
        }
        return -1;
    }
};
