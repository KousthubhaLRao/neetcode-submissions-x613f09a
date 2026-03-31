class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int rlow = 0, rhigh = rows-1;
        int clow = 0, chigh = cols-1;
        int rmid, cmid;

        while(rlow <= rhigh)
        {
            rmid = (rlow + rhigh) / 2;

            if(matrix[rmid][0] <= target and target <= matrix[rmid][chigh])
            {
                while(clow <= chigh)
                {
                    cmid = (clow + chigh) / 2;

                    if(matrix[rmid][cmid] == target) return true;
                    else if(matrix[rmid][cmid] > target) chigh = cmid - 1;
                    else clow = cmid + 1;
                }
                return false;
            }
            else if(matrix[rmid][0] > target) rhigh = rmid-1;
            else rlow = rmid+1;
        }
        return false;
    }
};
