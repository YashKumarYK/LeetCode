class Solution {
private:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    
public:
    
    bool isSafe(int x, int y, int n, int m){
        if(x<0 || y<0 || x>=n || y>=m){
            return false;
        }   
        return true;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        set<vector<int>> se;
        queue<vector<int>> q;     
        q.push({0,0,k});
        se.insert({0,0,k});
        int step=0;
        while(!q.empty()){
            int size=q.size();
            step++;
            while(size--){
                auto temp=q.front();
                q.pop();
                int x=temp[0];
                int y=temp[1];
                int rem=temp[2];
                if(x==n-1 && y==m-1){
                    return step-1;
                }
                
                for(int i=0;i<4;i++){
                    int n_x=x+dx[i];
                    int n_y=y+dy[i];
                    if(isSafe(n_x,n_y,n,m)){
                        if(n_x==n-1 && n_y==m-1){
                            return step;
                        }       
                        if(grid[n_x][n_y]==0){
                            if(se.find({n_x,n_y,rem})==se.end()){
                                q.push({n_x,n_y,rem});
                                se.insert({n_x,n_y,rem});
                            }
                        }
                        else if(rem>0){
                             if(se.find({n_x,n_y,rem-1})==se.end()){
                                q.push({n_x,n_y,rem-1});
                                se.insert({n_x,n_y,rem-1});
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};
