class Solution {
public:
    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 or c < 0 or r >= rows or c >= cols) return 0;
        if(grid[r][c] == 0) return 0;

        grid[r][c] = 0;

        return 1 + dfs(grid, r-1, c) + dfs(grid, r, c-1) + dfs(grid, r+1, c) + dfs(grid, r, c+1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0) continue;

                int area = dfs(grid, i, j);
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};
