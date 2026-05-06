/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:

    // 🔹 Convert tree into a string (Preorder traversal)
    // We include null markers ("#,") so structure is preserved
    string serialize(TreeNode *root)
    {
        // If node is null, mark it explicitly
        if (!root) return "#,";

        // Current node value + left subtree + right subtree
        return to_string(root->val) + "," 
             + serialize(root->left) 
             + serialize(root->right);
    }

    // 🔹 Z-function: computes longest prefix match starting at each index
    vector<int> z_function(const string &s)
    {
        int n = s.length();

        // z[i] = length of longest substring starting at i
        //        that matches prefix of s
        vector<int> z(n, 0);

        // [l, r] is the current "Z-box"
        // It represents a segment that matches prefix
        int l = 0, r = 0;

        // Start from index 1 (z[0] is always 0)
        for (int i = 1; i < n; i++)
        {
            // 🧠 If i is inside the current Z-box
            if (i <= r)
            {
                // We reuse previous computed values
                // z[i-l] corresponds to mirror position inside prefix
                z[i] = min(r - i + 1, z[i - l]);
            }

            // 🔍 Try to extend the match beyond current z[i]
            // Compare prefix (s[z[i]]) with current substring (s[i+z[i]])
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            {
                z[i]++;
            }

            // 🪟 If we extended beyond r, update the Z-box
            if (i + z[i] - 1 > r)
            {
                l = i;                   // new left boundary
                r = i + z[i] - 1;       // new right boundary
            }
        }

        return z;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        // 🔹 Serialize both trees
        string s = serialize(subRoot); // pattern
        string t = serialize(root);    // text

        // 🔹 Combine them with a separator
        // This prevents accidental overlap between pattern and text
        string combined = s + "|" + t;

        // 🔹 Compute Z-array on combined string
        vector<int> z = z_function(combined);

        int m = s.length(); // length of pattern

        // 🔹 Check for full match of pattern inside text
        for (int i = m + 1; i < combined.length(); i++)
        {
            // If Z value equals full pattern length → match found
            if (z[i] == m)
                return true;
        }

        return false;
    }
};