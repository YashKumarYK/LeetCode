class Solution {
public:
    
    bool canreplace( string &target, int pos, string &stamp){
        for( int i=0; i<stamp.size(); i++){
            if( target[pos+i]!= '?' && stamp[i] != target[pos+i]){
                return false;
            }
        }
        return true;
        
    }
    void replace( string & target, int pos, int len, int &count){
        for( int i=0; i<len ; ++i){
            if( target[pos+i]!= '?'){
                target[pos+i]= '?';
                count++;
            }
        }
        return;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        int slen = stamp.size();
        
        vector<bool> vis( target.size());  // for checking whether it has been replaced or not
        int cnt =0;
        
        vector<int> ans;
        while(cnt != n){
            
            bool ischanged = false;      // to check whether more it is still replacing or not , 
                                        //if not break the loop
            
            for( int i=0; i<= n-slen; ++i){
                if( !vis[i] && canreplace(target, i, stamp)){
                    replace( target, i, slen, cnt);
                    vis[i]= true;
                    ischanged = true;
                    ans.push_back(i);
                    
                    if( cnt == n) break;
                }
            }
            
            if( !ischanged) return {};
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};