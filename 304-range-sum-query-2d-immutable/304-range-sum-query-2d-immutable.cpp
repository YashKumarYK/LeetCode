class NumMatrix {
public:
    // vector<vector<int>> v(200, vector<int>(200, 0));
    int v[200][200];
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0 ; i<matrix.size(); i++){
            int sum =0;
            for(int j=0; j<matrix[0].size(); j++){
                sum+= matrix[i][j];
                v[i][j]= sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s1=0;
        int s2=0;
        for( int i=row1; i<= row2; i++){
            s1 += v[i][col2];
            if( col1 !=0)
                s2 += v[i][col1-1];
            else s2= 0;
        }
        return s1-s2;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */