class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        int r = m.size(), c = m[0].size();
        for(int i=1; i<r; i++){
            for(int j =1; j<c; j++){
                if(m[i][j] != m[i-1][j-1]) return false;
            }
        }
        return true;
    }
};