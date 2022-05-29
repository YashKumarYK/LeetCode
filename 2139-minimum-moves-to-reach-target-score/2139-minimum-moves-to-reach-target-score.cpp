#define rep( i,n) = for( int i=0;i<n; i++)
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        long long count =0;
        int dcount=0;
        while( target!= 1){
            if( dcount< maxDoubles){
                if( target %2 ==0){
                    target = target>>1;
                    dcount++;
                }
                else{
                    target--;
                }
                count++;
            }
            else{
                count += target -1;
                return count;
            }            
        }
        return count;
        
    }
};