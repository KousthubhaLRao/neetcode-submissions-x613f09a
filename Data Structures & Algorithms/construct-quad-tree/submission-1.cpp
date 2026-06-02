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
    Node *trueLeaf = new Node(true, true);

    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }

    Node *dfs(vector<vector<int>> &grid, int n, int r, int c)
    {
        if(n == 1) return grid[r][c] == 1 ? trueLeaf : falseLeaf;

        n /= 2;
        Node *topLeft = dfs(grid, n, r, c);
        Node *topRight = dfs(grid, n, r, c + n);
        Node *bottomLeft = dfs(grid, n, r + n, c);
        Node *bottomRight = dfs(grid, n, r + n, c + n);

        if(topLeft->isLeaf and topRight->isLeaf and bottomLeft->isLeaf and bottomRight->isLeaf and
            topLeft->val == topRight->val and topLeft->val == bottomLeft->val and topLeft->val == bottomRight->val) return topLeft;

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);

    }
};