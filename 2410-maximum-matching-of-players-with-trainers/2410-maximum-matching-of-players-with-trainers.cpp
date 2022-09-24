class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        
        int i=0, j=0;
        int cnt =0;
        while( i< p.size() && j<t.size()){
            while(j<t.size() && p[i]>t[j]){
                j++;
            }
            
            if( j<t.size() && p[i]<= t[j]){
                cnt++;
                i++, j++;
            }
        }
        return cnt;
    }
};