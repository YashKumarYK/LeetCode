class Solution {
public:
    bool solve( vector<vector<char>>& board, int x, int y, int row, int col,string word, int index, int n){
        //base condition
        if(index == n) return true;
        if( x<0|| x>=row || y<0 ||y>=col ) return false;
        if(board[x][y]!= word[index]) return false;
        
        
        else{
            
            board[x][y]='@';
            bool up = solve(board, x-1, y, row, col,word, index+1, n);
            bool down = solve(board, x+1, y, row, col,word, index+1, n);
            bool left = solve( board,x, y-1, row, col,word, index+1, n);
            bool right = solve( board,x, y+1, row, col,word, index+1, n);
            board[x][y] = word[index];
            return up|| down|| left|| right;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n= word.size();
        int index =0;
        int r = board.size();
        int c = board[0].size();
        for(int i =0; i<r; i++){
            for(int j=0; j<c; j++){
                if( board[i][j] == word[0] && solve( board, i,j,r,c, word, 0, n)){
                    return true;
                }
            }
        }
        return false;
    }
};