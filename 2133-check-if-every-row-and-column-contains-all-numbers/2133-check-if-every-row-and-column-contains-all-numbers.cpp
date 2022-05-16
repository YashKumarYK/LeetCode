class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n= matrix.size();
        for(int i=0; i<n; i++){
            for( int j=0; j<n; j++){
                int a = matrix[i][j];
                matrix[i][j]=0;
                for( int k=0; k<n; k++){
                    if( matrix[i][k] == a){
                        return false;
                    }
                    if( matrix[k][j] == a){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};