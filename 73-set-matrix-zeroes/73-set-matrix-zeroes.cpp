class Solution {
public:
//     bool ispossible(vector<vector<int>>& matrix, int r, int c, vector<vector<int>> visited){
//         if( ){
//             return true;
//         } 
//         else false
//     }
    
//     void Zeroes
    void setmatrix( int row, int col, vector<vector<int>> & matrix, int r, int c){
        for( int i=0; i<r; i++){
            if( matrix[i][col]!=0 && row != i)
                matrix[i][col]= -1;
        }
        for( int i=0; i<c; i++){\
            if( matrix[row][i]!=0 && col != i)
                matrix[row][i]= -1;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
//         vector<vector<int>> visited= matrix;
//         int r = matrix.size();
//         int c = matrix[0].size();
//         for( int i=0; i<r; i++){
//             for( int j=0; j<c; j++){
//                 visited[i][j]=-1;
//             }
//         }
        
//         for(int i=0; i<r; i++){
//             for(int j=0; j<c; j++){
//                 if(matrix[i][j] ==0 && visited[i][j]== -1){
                    
//                 }
//             }
//         }
        int r = matrix.size();
        int c= matrix[0].size();
        int cnt=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if( matrix[i][j]==0){
                    cnt ++;
                    setmatrix( i, j , matrix,r,c);
                }
            }
        }
        
        for(int i=0; i<r; i++){
            for( int j=0; j<c; j++){
                if(cnt ==0) break;
                else if( matrix[i][j] == -1 ){
                    matrix[i][j]= 0;
                }
            }
        }
        
    }
};