class Solution {
public:

    int solve( vector<vector<int>> & grid, int i, int j,int &cnt){
        if( i<0 || j<0|| i>=grid.size()|| j>= grid[0].size() ||grid[i][j]==-1) return 0;
        
        if( grid[i][j]== 2){
            if( cnt == -1)
                return 1;;
            return 0;
        }
        
        cnt--;
        grid[i][j]=-1;
        
        int count = solve( grid, i+1, j, cnt)+ solve( grid, i-1, j, cnt) 
                        +solve( grid, i, j+1, cnt) +solve( grid, i, j-1, cnt);
        grid[i][j] = 0;
        cnt++;
  
        return count;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int  r= grid.size();
        int c = grid[0].size();
        int cnt=0;
        int x=0,y=0;
        for( int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if( grid[i][j] == 0)
                    cnt++;
                
                if( grid[i][j]==1){
                    x= i;
                    y=j;
                }
            }
        }
            
        
        return solve( grid, x, y, cnt);
          
    }
};