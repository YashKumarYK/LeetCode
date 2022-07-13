class Solution {
public:
    
    
    bool solve( vector<int> &ms, int ind, vector<int> &s, int sum)\
    {
        if( ind == ms.size()){
            return s[0]==s[1] && s[1]== s[2] && s[2]==s[3];
        }
        
        for(int i=0; i<4; ++i){
            if( s[i]+ ms[ind]> sum) continue;
            else
            {
                s[i]+= ms[ind];
                if( solve(ms,ind+1, s, sum)) return true;   
                s[i]-=ms[ind];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& ms) {
        int n = ms.size();
        int sum = accumulate(ms.begin(), ms.end(), 0);
        if( sum %4 !=0 ) return false;
        sort( ms.begin(), ms.end(), greater<int> ());
        sum = sum/4;
        vector<int> s(4, 0);
        
        return solve( ms, 0, s, sum);
        
        
    }
};