class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         first approach
        for(int i=0; i< matrix.size(); i++){
            if (matrix[i][0]<=target&& matrix[i][matrix[0].size()-1]>target){
                int s=0;
                int e = matrix[0].size()-1;
                int mid = s + (e-s)/2;
                
                while(s<=e){
                    if(matrix[i][mid]== target){
                        return 1;
                    }
                    if( matrix[i][mid]>target){
                        e = mid-1;
                    }
                    if(matrix[i][mid]< target){
                        s = mid +1;
                    }
                    mid = s+ (e-s)/2;
                }
            }
            if (matrix[i][matrix[0].size()-1]==target) return 1;
        }
        return 0;
        
        
        // second approach
        // int rows = matrix.size();
        // int cols = matrix[0].size();
        // int e = rows*cols -1;
        // int mid = s+ (e-s)/2;
        // while(s<=e){
        //     if (matrix[mid/cols][mid%cols]== target) return 1;
        //     if (matrix[mid/cols][mid%cols]> target) e = mid-1;
        //     if (matrix[mid/cols][mid%cols]< target) s= mid+1;
        //     mid = s+(e-s)/2;
        // }
        // return 0;
    }
};