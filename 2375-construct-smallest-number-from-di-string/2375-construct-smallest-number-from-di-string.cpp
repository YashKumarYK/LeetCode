class Solution {
public:
    string smallestNumber(string pattern) {
        string s = "";
        int n = pattern.size();
        for( int i=1; i<=n+1; i++){
            s+= to_string(i);
        }
        string s1 = s;
        next_permutation(s1.begin(), s1.end());
        while(s!= s1){
            bool flag  = true;
            for( int i=0; i<pattern.size(); i++){
                if(pattern[i]=='I' && s1[i]< s1[i+1]){
                    continue;
                }
                if( pattern[i]=='D'&& s1[i]>s1[i+1]){
                    continue;
                }
                else{
                    flag = false;
                    break;
                }
                
            }
            if(flag == true){
                // cout<<"->>>>>>>>>>";
                break;
            }
            next_permutation(s1.begin(), s1.end());
        }
        return s1;
    }
};