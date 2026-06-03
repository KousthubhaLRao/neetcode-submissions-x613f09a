/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node *falseLeaf = new Node(false, true);
    Node *trueLeaf = new Node(true, true);  //this is a very clever optimisation. Instead of creating many individual leaves that are all similar, the solution reuses the same two leaf nodes everywhere.
    //So every cell containing 1 ultimately points to the same trueLeaf, and every cell containing 0 points to the same falseLeaf.
    //That's why returning topLeft during a merge is safe—it may literally be one of those shared leaf nodes.

    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }

    Node *dfs(vector<vector<int>> &grid, int n, int r, int c)
    {
        if(n == 1) return grid[r][c] == 1 ? trueLeaf : falseLeaf; //when the grid is just one cell, return the leaf with 1 if the value in the grid is 1, else return the leaf with 0
                                                                  //This is the base case in the recursion.
        n /= 2;
        Node *topLeft = dfs(grid, n, r, c);
        Node *topRight = dfs(grid, n, r, c + n);
        Node *bottomLeft = dfs(grid, n, r + n, c);
        Node *bottomRight = dfs(grid, n, r + n, c + n); //OHH i see what's happening. so the initial grid is passed into here starting with r and c as 0. Now to get the 4 children, we halve n
        // and add it to r and c to have them start at each of their starting cells within their respective grids. Eventually, they become nodes and their pointers will be returned. 

        if(topLeft->isLeaf and topRight->isLeaf and bottomLeft->isLeaf and bottomRight->isLeaf and
            topLeft->val == topRight->val and topLeft->val == bottomLeft->val and topLeft->val == bottomRight->val) return topLeft; //if all 4 children are leaves with all same values, 
            // then they can all be merged into one leaf and the topLeft can be returned as the pointer to this new leaf. Though it doesn't matter which pointer we return since
            //they're all identical. 

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        //else, the 4 quadrants cannot be merged into a single leaf. So, a new internal node is created whose children are the trees of the 4 quadrants.
    }
};




























