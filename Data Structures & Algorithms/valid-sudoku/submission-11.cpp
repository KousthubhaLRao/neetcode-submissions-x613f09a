class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r[9] = {0}, c[9] = {0}, s[9] = {0};
        int box, bi, mask;

        for(int i = 0; i < 9 ; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue;

                //bi = bit index
                bi = board[i][j] - '1';
                box = (i/3)*3 + (j/3);
                mask = 1 << bi;

                if((r[i] & mask) or (c[j] & mask) or (s[box] & mask)) return false;

                r[i] |= mask;
                c[j] |= mask;
                s[box] |= mask;
            }
        }
        return true;
    }
};
