class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 2) q.push({i, j}); //initialise the queue with positions of all rotten oranges
                if(grid[i][j] == 1) fresh++;  //to count total number of fresh oranges
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(fresh > 0 and !q.empty()) //while queue is not empty and there still are fresh oranges
        {
            int length = q.size(); 
            for(int i = 0; i < length; i++) //this loop runs only as many times as the number of newly rotten oranges from the previous iteration. 
            {
                auto curr = q.front(); q.pop();

                int r = curr.first;
                int c = curr.second;

                for(const auto &dir : directions) //this is the loop that iterates through the 4 directions
                {
                    int row = r + dir.first;
                    int col = c + dir.second;
                    if(row >= 0 and row < grid.size() and col >= 0 and col < grid[0].size() and grid[row][col] == 1)
                    {
                        grid[row][col] = 2; //basically, look for a fresh orange in the 4 surrounding directions of a rotten orange and make it rotten 
                        q.push({row, col}); //the rot propagates, so the new coords of the freshly rotten oranges also have to be pushed onto the queue for bfs
                        fresh--;
                    }
                }
            }
            time++;  //every time the outer for loop runs is 1 level of bfs. 
        }

        return fresh == 0 ? time : -1; //self explanatory
    }
};


//another multi source bfs problem.
//time elapsed is counted by levels of bfs. 1 level = 1 minute. 
//answer is -1 if at the end, there's a fresh orange left. 