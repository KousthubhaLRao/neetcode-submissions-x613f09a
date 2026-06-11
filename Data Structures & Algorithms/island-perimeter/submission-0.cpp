class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0; //perimeter

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0) continue; //i don't want anything to do with lake cells

                p += 4; //else
                if(i and grid[i-1][j]) p -= 2;
                if(j and grid[i][j-1]) p -= 2;
            }
        }
        return p;
    }
};