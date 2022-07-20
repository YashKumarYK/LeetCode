class Solution {
public:
    
    vector<int> leftsmaller( vector<int> & h){
        stack<int> s;
        s.push(-1);
        vector<int> ans(h.size());
        for(int i=0;i<h.size(); i++){
            while( s.top()!=-1 && h[s.top()]>=h[i]){
                s.pop();
            }
            ans[i]= s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> rightsmaller( vector<int> & h){
        stack<int> s;
        s.push(-1);
        vector<int> ans(h.size());
        for(int i=h.size()-1;i>=0; --i){
            while( s.top()!=-1 && h[s.top()]>=h[i]){
                s.pop();
            }
            ans[i]= s.top();
            
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& h) {
        vector<int> left = leftsmaller(h);
        vector<int> right= rightsmaller(h);
        int maxArea = 0;
        for(int i=0; i<h.size(); i++){
            int hgt =  h[i];
            int b1 = right[i]<0?h.size(): right[i];
            int b2= left[i];
            int base = b1-b2-1;
            maxArea = max( maxArea, base*hgt);
        }
        return maxArea;
    }
};