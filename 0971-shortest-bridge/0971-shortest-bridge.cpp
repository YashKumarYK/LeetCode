class Solution {
public:
    queue<pair<int,int>> q;
    int dir[5] = {1, 0, -1, 0, 1};
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int x, int y){
        if(x<0 || y<0 || x==grid.size()|| y==grid[0].size() || grid[x][y]==0 || vis[x][y]==1) return;
        vis[x][y]=1;
        q.push({x, y});
        for(int i=0;i<4;i++){
            dfs(grid, vis, x+dir[i] , y+ dir[i+1]);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        bool found= false;
        for(int i=0;i<n;i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1){
                    dfs(grid, vis, i, j);
                    found= true;
                    break;
                }
            }
            if(found) break;
        }

        int step =0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto curr = q.front();
                q.pop();
                for(int i=0;i<4; i++){
                    int newX = curr.first+ dir[i];
                    int newY = curr.second+dir[i+1];
                    
                    if(newX<0 || newY<0 || newX==n|| newY ==m || vis[newX][newY]==1) continue;
                    
                    if(grid[newX][newY]==1) return step;
                    
                    q.push({newX, newY});
                    vis[newX][newY]=1;

                }
            }
            step++;
        }
        return -1;
    }
   
};