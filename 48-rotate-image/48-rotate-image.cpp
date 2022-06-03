class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c= matrix[0].size();
        vector<int> v;
        for(int j = 0 ; j<c ; j++){
            for( int i= r-1; i>=0; i--){
                v.push_back(matrix[i][j]);
            }
        }
        int k =0;
        
        for( int i =0; i< r; i++){
            for( int j=0; j<c; j++){
                matrix[i][j] = v[k++];
            }
        }
        
    }
};