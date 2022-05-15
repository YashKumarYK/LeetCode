class Solution {
public:
    bool ispossible(int row, int col, int i, vector<vector<char>> &board){
        //for row check
        for( int j= 0; j<9; j++){
            if( board[row][j]== i)
                return false;
            if( board[j][col]==i)
                return false;
            if( board[3*( row/3) + j/3][3*(col/3)+j%3]== i)
                return false;
        }
        return true;
    }
    bool solve( vector<vector<char>>& board , int col){        
        //main code
        for(int col= 0; col<=8; col++){
            
            for( int row =0; row<=8; row++){
                
                if( board[row][col] == '.'){
                    
                    for(char i = '1'; i<= '9'; i++){
                        if( ispossible( row, col, i, board)){
                            board[row][col] = i;
                            if (solve(board, col+1)){
                                return true;
                            }
                            else
                                board[row][col]= '.';
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {

        int col=0;
        solve( board, col);
    }
};