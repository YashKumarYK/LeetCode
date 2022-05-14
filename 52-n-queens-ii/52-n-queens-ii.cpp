class Solution {
public:
    void solve( int &count, int col, vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag, int n){
        //base case
        if(col==n){
            count++;
            return;
        }
        
        for( int row= 0; row< n; row++){
            if( leftRow[row]==0 && upperDiag[row+col]==0 && lowerDiag[n-1 + col-row]==0){
                leftRow[row]=1;
                upperDiag[row+col] =1;
                lowerDiag[n-1+ col-row]=1;
                
                //recursive call
                solve( count,col+1, leftRow, upperDiag, lowerDiag, n);
                
                //backtracking
                leftRow[row]=0;
                upperDiag[row+col] =0;
                lowerDiag[n-1+ col-row]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> leftRow(n,0);
        vector<int> upperDiag( 2*n-1,0);
        vector<int> lowerDiag( 2*n-1,0);
        int count=0;
        solve( count, 0, leftRow, upperDiag, lowerDiag, n);
        return count;
    }
};