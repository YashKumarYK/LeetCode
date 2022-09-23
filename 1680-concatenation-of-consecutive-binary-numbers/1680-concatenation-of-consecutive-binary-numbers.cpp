class Solution {
public:
    
//     void solve1( string &s, int n ){
//         int ans = 0;
//         while(n!=0){
//             ans = ans*
//         }
//     }
    
//     long long solve2( string &s){
//         long long  ans =0;
//         long long f=1;
//         for(int i=s.size()-1; i>=0; --i){
//             int n = s[i]-'0';
//             ans = n*f + ans;
//             f=f*2;
//         }
//         return ans;
//     }
//     int concatenatedBinary(int n) {
//         string s ="";
//         for( int i=0; i<=n; i++){
//             solve1(s,i);
//             // cout<<s<<endl;
//         }
//         cout<<s<<endl;
//         long long ans = solve2(s);
//         int m = 1e9+7;
//         return ans%m;
        
//     }
    const long moduloNum = pow(10.0, 9.0) + 7;
    double ff;
    
    int concatenatedBinary(int n) {
        return recurseHelper(n);
    }
    
    long recurseHelper(int n) {
        if(n == 1) return 1;
        return ((recurseHelper(n-1)<<(((*(1+(uint32_t *)&(ff=(double) (n|1))))>>20)-1023+1))|n)%moduloNum;
    }
};