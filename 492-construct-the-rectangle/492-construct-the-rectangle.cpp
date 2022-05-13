class Solution {
public:
    vector<int> constructRectangle(int area) {
        int length = sqrt(area);
        for( int i=length; i>0; i--){
            if( area%i == 0){
                length =i;
                break;
            }
        }
        int width = area/length;
        
        if(length>=width) return {length, width};
        else
            return {width,length};
    }
};