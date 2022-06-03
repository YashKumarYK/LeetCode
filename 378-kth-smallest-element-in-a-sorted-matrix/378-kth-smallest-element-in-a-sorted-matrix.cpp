class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxHeap;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> v(m*n,0);
        for(int i=0; i < m; i++){
            for(int j=0; j < n ; j++){
                v[i*n +j]= matrix[i][j];
            }
        }
        sort(v.begin(), v.end());
        // for(int i=0; i<v.size(); i++)
        
        for( int i=0; i<k; i++){
            maxHeap.push(v[i]);
        }
        
        for( int i=k; i<n-1; i++){
            if(v[i]<= maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(v[i]);
            }
        }
        return maxHeap.top();
    }
};