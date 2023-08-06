class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // int i= 0;
        // int j=n-1;
        // while(i<m && j>=0){
        //     if(matrix[i][j]== target) return true;
        //     else if(matrix[i][j]<target){
        //         i++;
        //     }else{
        //         j--;
        //     }
        // }
        // return false;
        int s =0, e = (n*m)-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(matrix[mid/n][mid%n]== target){
                return true;
            }
            else if(matrix[mid/n][mid%n] < target){
                s = mid+1;
            }else{
                e= mid-1;
            }
        }
        return false;
    }
};