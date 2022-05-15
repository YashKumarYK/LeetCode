class Solution {
public:
//     vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
//         int row = mat.size();
//         int col= mat[0].size();
//         if( row * col != r*c) return mat;
//         vector<int> v( row*col);
//         for(int i=0; i<row;i++){
//             for(int j=0; i<col; j++){
//                 v[col*i + j] = mat[i][j];
//             }
//         }
//         // int k=0;
//         vector<vector<int>> s(r,vector<int> (c));
//         // for( int i=0; i<r; i++){
//         //     for(int j=0; j<c; j++){
//         //         s[i][j]= v[k++];
//         //     }
//         // }
//         int i=0;
//         while(i< v.size()){
//             v[i/c][i%c]=s[i];
//             i++;
//         }
//         return s;
        
//     }
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(),n=mat[0].size();
        vector<vector<int>>ans(r,vector<int>(c,0));
        if(m*n != r*c) return mat;
        for(int i=0;i<m*n;i++) {
            ans[i/c][i%c] = mat[i/n][i%n];
        }
        return ans;
    }
};