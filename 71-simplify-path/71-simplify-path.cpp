class Solution {
public:
    string simplifyPath(string p) {
        int n = p.size();
        stack<string> s;
        int i=0;
        for(int i=0; i<n; i++){
            if( p[i]=='/'){
                continue;
            }
            if( p[i]=='.'){
                string temp="";
                while( i<n && p[i]!='/'){
                    temp.push_back(p[i]);
                    i++;
                }
                
                if( temp==".."){
                    if( !s.empty()) s.pop();
                }
                else if( temp==".") continue;
                else{
                    s.push(temp);   
                }
            }
            else{
                string temp="";
                while( i<n && p[i]!='/'){
                    temp.push_back(p[i]);
                    i++;
                }
                s.push(temp);
            }
        }
        string ans = "";
        if(s.empty()) ans = ans+"/";
        while(!s.empty()){
            ans="/"+s.top()+ans;
            s.pop();
        }
        return ans;
    }
};