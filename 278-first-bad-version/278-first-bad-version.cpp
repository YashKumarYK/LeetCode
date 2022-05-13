// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int solve( int n, int i){
        if( isBadVersion(i)) return i;
        // if(i==n){
        //     return 
        // }
        else{
            return (solve(n, i+1));
        }
    }
    int firstBadVersion(int n) {
        int ans = solve(n, 1);
        return ans;
    }
};