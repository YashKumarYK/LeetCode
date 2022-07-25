class Solution {
public:
    
//     int countn( string st , int s, int e ){
//         bool c = false;
//         int endind= -1;
//         int startind =-1;
//         int count =0;
//         int n=0;
//         for(int i=s; i<=e; i++){
//             if(c==true){
//                 count++;
//             }
//             if(st[i]=='|'){
//                 if( c== false){
//                     c= true;
//                     startind= i; 
//                 }
//                 n++;
//                 endind=i;
//             }
//         }
        
//         if( n==0 || n==1 ) return 0;
//         return ((endind - startind+1)- n);
//     }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> v;
        
        for(int i=0; i<s.size(); ++i){
            if( s[i]=='|'){
                v.emplace_back(i);
            }
        }
        vector<int> ans;
        for(auto i: queries){
            if( i[0]==i[1] || i[1]-i[0]==1){
                ans.emplace_back(0);
                continue;
            }
            int st = lower_bound(v.begin(), v.end(),i[0]) - v.begin();
            int e = upper_bound(v.begin(), v.end(), i[1]) - v.begin();
            
            --e;
            int count =  (v[e]-v[st]+1)- (e-st+1);
            count = count<0? 0: count;
            ans.emplace_back( count);
        }
        return ans;
    }
};