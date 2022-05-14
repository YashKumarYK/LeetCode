class Solution {
public:
    
    //this will cause TLE
//     bool isSafe( int col, int row,  vector<string> output, int n){
//         int drow= row;
//         int dcol = col;
        
//         while( col>=0 && row>=0){
//             if(output[row][col]=='Q') return false;
//             col--;
//             row--;
//         }
        
//         row= drow;
//         col= dcol;
//         while( dcol--){
//             if( output[row][col]== 'Q') return false;
//         }
        
//         while( row<n && col>=0){
//             if( output[row][col] == 'Q') return false;
//         }
        
//         return true;
//     }
    
//     void solve( int col, vector<vector<string>> &ans, vector<string> output, int n){
//         if( col==n-1){
//             ans.push_back(output);
//             return;
//         }
//         //for every column we are checking the columns ans after the saf condition we push the "Q "into the board( output vector)
//         for( int row =0; row< n; row++){
//             if( isSafe( col, row, output, n)){
//                 output[row][col]= 'Q';
//                 solve( col+1, ans, output, n);
//                 output[row][col]= '.';
//             }
//         }
//     }
    
    void solve(int col, vector<vector<string>> &ans, vector<string> board, int n,  vector<int> leftRow , vector<int> upperDiag ,vector<int> lowerDiag){
        if ( col==n){
            ans.push_back(board);
            return;
        }
        
        //we are checking every row for each column
        for( int row =0; row<n; row++){
            if( leftRow[row]==0 && upperDiag[row+ col] ==0 && lowerDiag[n-1 + col-row]==0){
                board[row][col] = 'Q';
                leftRow[row]=1;
                upperDiag[row+col]= 1;
                lowerDiag[n-1 + col-row]=1;
                
                //recursive call
                solve( col+1, ans, board, n, leftRow, upperDiag, lowerDiag);
                
                //backtracking
                board[row][col] = '.';
                leftRow[row]=0;
                upperDiag[row+col]= 0;
                lowerDiag[n-1 + col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ;
        vector<string> board(n);
        string str(n, '.');
        
        for(int i=0; i<n ; i++){
            board[i]= str;
        }
        //using extra space for the condition check
        vector<int> leftRow(n, 0);
        vector<int> upperDiag( 2*n-1, 0);
        vector<int> lowerDiag( 2*n-1, 0);
        
        solve( 0, ans, board, n, leftRow, upperDiag, lowerDiag);
        return ans;
    }
};