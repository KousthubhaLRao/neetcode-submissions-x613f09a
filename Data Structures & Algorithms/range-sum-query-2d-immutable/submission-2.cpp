class NumMatrix {
private: vector<vector<int>> pre;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        pre = vector<vector<int>>(rows, vector<int>(cols,0));
        int sum;
        for(int i = 0; i < rows; i++)
        {
            sum = 0;
            for(int j = 0; j < cols; j++)
            {
                sum += matrix[i][j];
                pre[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++)
        {
            sum += pre[i][col2];
            if(col1 > 0) sum -= pre[i][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */