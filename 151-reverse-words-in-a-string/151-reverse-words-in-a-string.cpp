class Solution {
public:
    string reverseWords(string s) {
        int st =0;
        int end= s.size()-1;
        
        while( s[st]==' '){
            st++;
        }
        while( s[end]==' '){
            end--;
        }
  
        s = s.substr(st, end-st+1);
        
        int n = s.size();
 
        int start = 0;
        end =0;
        for(int i=0; i<s.size(); i++){
            if( s[i]==' '){
                end = i-1;
                reverse( s.begin()+ start, s.begin()+end+1);
                start = i+1;
                while( s[i]==' '){
                    i++;
                }
                s.erase(start, i-start); 
                i=start;
            }
        }
        reverse( s.begin() +start, s.end());
        reverse(s.begin(), s.end()); 
        return s;
    }
};