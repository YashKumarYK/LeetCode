class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for( int row =0; row < 9; row++ ){
            for( int col =0; col<9; col++){
                if( board[row][col] =='.')
                    continue;
                int i= board[row][col];
                board[row][col]='0';
                for( int j= 0; j<9; j++){
                    if( board[row][j]== i )
                        return false;
                    if( board[j][col]==i)
                        return false;
                    if( board[3*( row/3) + j/3][3*(col/3)+j%3]== i)
                        return false;
                }
                board[row][col]=i;
            }
        }
        //for row check
        
        return true;
    }
};