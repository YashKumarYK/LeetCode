class Solution {
public:
    vector<int> leftRow, upperDiag, lowerDiag;
    // bool isValid(int row, int col, vector<string> &board, int n){
    //     int r = row;
    //     int c = col;
    //     // for check the left side row
    //     for(int c= col; c>=0; c--){
    //         if(board[row][col]=='Q') return false;
    //     }

    //     //for upper diagonal
    //     while(r>=0 && c>=0){
    //         if(board[row][col]=='Q') return false;
    //         row--;
    //         col--;
    //     }
    //     r = row, c = col;
    //     while(r<n && c>=0){
    //         if(board[row][col]=='Q') return false;
    //         row++;
    //         col--;
    //     }

    //     return true;
    // }
    void solve(vector<string> &board, int n, int col, vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(!leftRow[row] && !upperDiag[n-1+ col-row] && !lowerDiag[row+col]){
                board[row][col] = 'Q';
                leftRow[row]= 1;
                upperDiag[n-1+col-row] =1;
                lowerDiag[row+col] = 1;

                solve(board, n, col+1, ans);
                
                board[row][col] = '.';
                leftRow[row]= 0;
                upperDiag[n-1+col-row] =0;
                lowerDiag[row+col] = 0;
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
        leftRow.resize(n, 0);
        upperDiag.resize(2*n-1, 0);
        lowerDiag.resize(2*n-1, 0);
        solve(board, n, 0, ans);
        return ans;
    }
};