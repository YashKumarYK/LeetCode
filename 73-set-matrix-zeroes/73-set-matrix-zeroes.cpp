class Solution {
public:

    // void setmatrix( int row, int col, vector<vector<int>> & matrix, int r, int c){
    //     for( int i=0; i<r; i++){
    //         if( matrix[i][col]!=0 && row != i)
    //             matrix[i][col]= -1;
    //     }
    //     for( int i=0; i<c; i++){\
    //         if( matrix[row][i]!=0 && col != i)
    //             matrix[row][i]= -1;
    //     }
    // }
    void setZeroes(vector<vector<int>>& matrix) {
       
        //Appraoch #1 - Brute Force 
        int r = matrix.size();
        int c= matrix[0].size();
//         int cnt=0;
//         for(int i=0; i<r; i++){
//             for(int j=0; j<c; j++){
//                 if( matrix[i][j]==0){
//                     cnt ++;
//                     setmatrix( i, j , matrix,r,c);
//                 }
//             }
//         }
        
//         for(int i=0; i<r; i++){
//             for( int j=0; j<c; j++){
//                 if(cnt ==0) break;
//                 else if( matrix[i][j] == -1 ){
//                     matrix[i][j]= 0;
//                 }
//             }
//         }
        
        //approach #2 - using two dummy  vectors
        bool row0= false ;
        bool col0 = false;
        
        //for checking if 0th col ans 0th row has 0 or not
        //for the first row
        for( int j=0; j<c; j++){
            if( matrix[0][j]== 0 ) row0 = true; 
        }
        
        //for the first column
        for( int i=0; i<r; i++){
            if( matrix[i][0]==0) col0 = true;
        }
        
        
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                if( matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        //checking for rows using 1st column
        for( int i=1; i<r; i++ ){
            if( matrix[i][0]==0){
                for( int j=1; j<c; j++){
                    matrix[i][j]=0;
                }
            }
        }
        for( int j=1; j<c; j++ ){
            if( matrix[0][j]==0){
                for( int i=1; i<r; i++){
                    matrix[i][j]=0;
                }
            }
        }
        
        if( row0){
            for(int i=0; i<c;i++){
                matrix[0][i]=0;
            }
        }
        if( col0){
            for(int i=0; i<r;i++){
                matrix[i][0]=0;
            }
        }
        
        
        
    }
};