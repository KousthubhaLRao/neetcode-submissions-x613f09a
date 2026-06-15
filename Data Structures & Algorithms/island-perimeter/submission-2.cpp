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
                if(i and grid[i-1][j]) p -= 2; //If the cell above is also land, subtract 2.
                if(j and grid[i][j-1]) p -= 2;  //If the cell to the left is also land, subtract 2.
            }
        }
        return p;
    }
};  //ok so basically, just add 4 for every land cell. subtract 2 for every line that you can see between two land cells that doesn't get counted as perimeter.