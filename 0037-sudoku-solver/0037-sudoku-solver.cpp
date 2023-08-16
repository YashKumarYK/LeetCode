class Solution {
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char ch){
        for(int i=0;i<9;i++){
            if(board[i][col]==ch) return false;
            if(board[row][i]==ch) return false;

            if(board[3*(row/3)+i/3][3*(col/3) + i%3]== ch ) return false;
        }
        return true;
    } 

    bool solve(vector<vector<char>> & board){
        for(int col=0; col<9; col++){
            for( int row =0;row<9; row++){
                if(board[row][col]=='.'){
                    for(char ch='1'; ch<='9';ch++){
                        if(isValid(board, row, col, ch)){
                            board[row][col] = ch;
                            if(solve(board)){
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
        solve(board);
    }
};