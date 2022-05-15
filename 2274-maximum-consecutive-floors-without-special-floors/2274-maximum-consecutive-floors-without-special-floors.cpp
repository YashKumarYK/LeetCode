class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        sort(special.begin(), special.end());
        
        int t =1;

        int curr=special[0]-bottom;
        while( t< n){
            curr = max( curr, special[t]- special[t-1]-1);
            t++;
        }
        curr = max( curr, top- special[n-1]);
        return curr;
    }

};