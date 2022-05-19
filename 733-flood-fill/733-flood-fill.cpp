class Solution {
public:
    
    void solve( vector<vector<int>> & image, int x, int y, int m, int n, int newColor, int color){
        if( x<0 || y<0 ||x>=m || y>=n ||  image[x][y]!=color ||image[x][y]== newColor){
            return;
        }
            
        image[x][y]= newColor;
        
        solve(image, x-1, y, m,n, newColor, color);
        solve(image, x+1, y, m,n, newColor, color);
        solve(image, x, y+1, m,n, newColor, color);
        solve(image, x, y-1, m,n, newColor, color);
        return;   
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m= image.size();
        int n= image[0].size();
        int color = image[sr][sc];
        if( color== newColor) return image;
        solve(image, sr, sc,m, n, newColor, color);
        return image;
    }
};