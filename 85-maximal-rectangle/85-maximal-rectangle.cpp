class Solution {
public:
    vector <int> nextSmallerElement( vector<int>&arr, int n ){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            int curr= arr[i];
            while( s.top()!= -1 && arr[s.top()] >= curr){
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector <int> prevSmallerElement( vector<int>&arr, int n ){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0; i< n ; i++){
            int curr= arr[i];
            while( s.top()!= -1 && arr[s.top()] >= curr){
                s.pop();
            }
            
            ans[i]= s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next(n);
        int area= -100;
        next = nextSmallerElement(heights,n);
        
        vector<int> prev(n);
        prev= prevSmallerElement(heights, n);
        
        for(int i=0; i<n; i++){
            int l = heights[i];
            
            
            if (next[i]== -1){
                next[i]= n;
            }
            
            int b = next[i]- prev[i]-1;
            int newArea= l*b;
            area = max(area, newArea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> height(c, 0);
        int maxArea =0;
        for(int i=0; i<r; i++){
            for( int j=0; j<c; j++){
                if(matrix[i][j]=='1') height[j]++;
                else{
                    height[j]=0;
                }
                cout<<height[j]<<" ";
            }
            cout<<endl;
            maxArea = max( maxArea, largestRectangleArea( height));
        }
        
        return maxArea;
    }
};