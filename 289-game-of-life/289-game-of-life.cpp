class Solution 
{
public:
    int neighbor(vector<vector<int>>& board, int x, int y){
        int n = board.size();
        int m = board[0].size();
        if( x>=0 &&x<n && y>=0&& y<m &&board[x][y]==1) return 1;
        else return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> arr( n , vector<int> (m, 0));
        // int arr = new int[n][m]; 
        for(int i=0; i<n; i++){
            for( int j=0; j<m; j++){
                int liveneighbor= neighbor(board, i-1,j-1)+neighbor(board, i-1,j)+
                    neighbor(board, i-1,j+1)+neighbor(board, i,j-1)+
                    neighbor(board, i,j+1)+neighbor(board, i+1,j-1)+
                    neighbor(board, i+1,j)+neighbor(board, i+1,j+1);
                
                if(board[i][j]==1) {
                    if(liveneighbor<2||liveneighbor>3) arr[i][j]=0;
                    else arr[i][j]= 1;
                }
                if(board[i][j]==0){
                    if (liveneighbor==3) arr[i][j]=1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for( int j=0; j<m; j++){
                board[i][j]= arr[i][j];
            }
        }
            
    }
};