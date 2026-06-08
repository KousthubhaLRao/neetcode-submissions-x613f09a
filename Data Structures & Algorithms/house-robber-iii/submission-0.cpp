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
    int rob(TreeNode* root) {
        auto result = dfs(root);  //auto is pair, but ok whatever
        return max(result.first, result.second);
    }

    pair<int, int> dfs(TreeNode *root)
    {
        if(!root) return {0, 0};

        auto leftPair = dfs(root->left);  //REFER GREEEN DSA BOOK FOR THE DRY RUN
        auto rightPair = dfs(root->right);

        int withRoot = root->val + leftPair.second + rightPair.second;
        int withoutRoot = max(leftPair.first, leftPair.second) + max(rightPair.first, rightPair.second);

        return {withRoot, withoutRoot};
    }
};


// the basic logic in this house robber problem is, you either rob a house, or you skip it and rob the next house.
// If the current house gets robbed, the next house can't get robbed, so we skip to the grandchild house. 
// If we skip the current house, then we can CONSIDER robbing the next house. (it doesn't necessarily have to be robbed)

// The output has to be the max of these two options. 