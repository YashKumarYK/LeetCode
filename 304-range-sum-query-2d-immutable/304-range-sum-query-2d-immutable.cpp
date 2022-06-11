class NumMatrix {
public:
    // vector<vector<int>> v(200, vector<int>(200, 0));
    int v[201][201]={0};
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                v[i+1][j+1] = v[i][j+1]+ v[i+1][j]+ matrix[i][j] - v[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return  v[row2+1][col2+1] - v[row1][col2+1] - v[row2+1][col1] + v[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */