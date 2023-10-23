class Solution {
public:
    bool isPowerOfFour(int n) {
        if( n<1) return false;
        while( n%4==0 && n!=1){
            n= n>>2;
            cout<<n<<" ";
        }
        cout<<endl;
        if( n==1) return true;
        if( n%4!=0) return false;
        return true;
    }
};