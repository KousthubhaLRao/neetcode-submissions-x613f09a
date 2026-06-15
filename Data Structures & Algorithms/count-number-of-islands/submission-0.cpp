class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 or c < 0 or r >= rows or c >= cols) return; //all invalid values.

        if(grid[r][c] == '0') return; //we don't want anything to do with either visited cells or lake cells

        grid[r][c] = '0'; //marking it as visited.

        dfs(r, c-1, grid);
        dfs(r-1, c, grid);
        dfs(r, c+1, grid);
        dfs(r+1, c, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int island_count = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    island_count++;  //every time a 1 is found, it's a new island.
                    dfs(i, j, grid);
                }
            }
        }
        return island_count;
    }
};
