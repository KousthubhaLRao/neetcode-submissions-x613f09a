class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q; //all treasure chests locations will be put in this queue, which will later be processed throuh bfs.
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0) q.push({i, j});
            }
        }

        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}}; //directions : up, down, left, right

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second; q.pop();

            for(int i = 0; i < 4; i++)
            {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];  //this neatly iterates through all 4 neighbours

                if(r < 0 or r >= m or c < 0 or c >= n or grid[r][c] != INT_MAX) continue; 
                //this filters invalid cells and treasure chests and water cells

                grid[r][c] = grid[row][col] + 1; //this line marks the land cells with levels or distance from treasure chest.
                q.push({r, c}); // to further propagate the bfs. 
            }
        }
    }
};

//multi source bfs. (instead of bfs from land cells, we run bfs from treasure chests and look for shortest paths to every land cell. 
//                   and since we're running bfs, the algo will automatically mark land cells with the level number, which will also be the shortest distance)