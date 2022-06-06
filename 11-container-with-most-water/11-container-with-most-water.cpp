class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int e = height.size()-1;
        int maxArea = INT_MIN;
        while(s<e){
            int h = min( height[s], height[e]);
            int area = h*(e-s);
            maxArea = max( area, maxArea);
            if( height[s]> height[e]){
                e--;
            }
            else s++;
        }
        return maxArea;
    }
};