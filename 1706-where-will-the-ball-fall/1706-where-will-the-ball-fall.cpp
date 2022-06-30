class Solution {
public:
    
    bool solve( int i, int j, int r, vector<vector<int>>& a, int &col){
        if( i== r) {
            col = j;
            return true;
        }
        if( (j==-a[0].size() -1 && a[i][j]==1) || (j==0 && a[i][j]==-1)) return false;
        
        if( a[i][j]== -1 ){
             if(a[i][j-1]== -1){
                 return solve( i+1, j-1, r, a, col);
             }
            return false;
        }
        
        else if(a[i][j] ==1){
            if( a[i][j+1]==1){
                return solve( i+1, j+1, r, a, col);
            }
            return false;
        }
        return true;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        if( c==1) return {-1};
        vector<int> ans;
        for(int i=0; i<c; i++){
            int col = -1;
            if(solve( 0, i, r, grid, col)) ans.push_back(col);
            else ans.push_back(-1);
        }
        return ans;
               
    }
    
};