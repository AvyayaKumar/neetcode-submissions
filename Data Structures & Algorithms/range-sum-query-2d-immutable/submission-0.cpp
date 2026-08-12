class NumMatrix {
public:
    vector<vector<int>> sumMat;
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(); int c = matrix[0].size();
        vector<vector<int>> sumMat(r+1, vector<int>(c+1, 0));
        for (int i = 0; i < r; i++) {
            int rowTotal = 0;
            for (int j = 0; j < c; j++) {
                rowTotal += matrix[i][j];
                sumMat[i+1][j+1] = rowTotal + sumMat[i][j+1];
            }
        } 
        this->sumMat = sumMat;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMat[row2+1][col2+1] - sumMat[row1][col2+1] - sumMat[row2+1][col1] + sumMat[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */