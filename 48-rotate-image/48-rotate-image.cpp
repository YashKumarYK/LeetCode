class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c= matrix[0].size();
//         vector<int> v;
//         for(int j = 0 ; j<c ; j++){
//             for( int i= r-1; i>=0; i--){
//                 v.push_back(matrix[i][j]);
//             }
//         }
//         int k =0;
        
//         for( int i =0; i< r; i++){
//             for( int j=0; j<c; j++){
//                 matrix[i][j] = v[k++];
//             }
//         }
        
        //approach #2 
        // inplace 
        for(int i=0; i<r; ++i){
            for( int j=i+1; j<c; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i =0; i<r; ++i){
            reverse( matrix[i].begin(),matrix[i].end());
        }
        
    }
};