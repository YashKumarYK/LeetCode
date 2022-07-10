class Solution {
public:
    bool canChange(string s, string t) {
        if( s.size()!= t.size()) return false;
        string s1, s2;
        for(int i=0; i<s.size(); i++){            
            if( s[i]!='_') s1.push_back(s[i]);
            if(t[i]!='_') s2.push_back(t[i]);
        }
        
        if( s1!= s2) return false;
        int i=0;
        
        vector<int> v1,v2;
        for(int i=0; i<s.size(); i++){
            if( s[i]!= '_') v1.push_back(i);
            if( t[i]!= '_') v2.push_back(i);
        }
        
        int n= v1.size();
        for(int i=0; i<n; i++){
            if( s[v1[i]]=='L'){
                if(v1[i]<v2[i])
                    return false;
            }
            else if(s[v1[i]]=='R'){
                if( v1[i]>v2[i])
                    return false;
            }
        }
        return true;
//         while(i<s.size()){
//             if( s[i]=='L'){
//                 int j=i;
//                 while( t[j]!=s[i] && j>=0){   
//                     j--;
//                 }
//                 if(j<0) return false;
//                 else{
//                     t[j]='_';
//                 }
//             }
//             else if( s[i]=='R'){
//                 int j=i;
//                 while( t[j]!= s[i] && j<s.size()){
//                     j++;
//                 }
//                 if( j==s.size() ) return false;
                
//                 else{
//                     t[j]= '_';
//                 }
//             }
//             i++;
//         }
        return true;
    }
};