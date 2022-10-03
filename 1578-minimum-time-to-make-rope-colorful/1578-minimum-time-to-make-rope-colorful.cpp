class Solution {
public:
    int minCost(string c, vector<int>& nt) {
        int n = c.size();
        int time =0;
        int tt = accumulate(nt.begin(), nt.end(), 0);
        int i=0;
        
        while( i<c.size()){
            int maxi = nt[i];
            int j=i;
            while( i<n-1 && c[i]==c[i+1]){
                maxi = max(maxi, nt[i+1]);
                i++;
            }
          
            time += maxi;
            i++;
        } 
            
        return tt- time;
    }
};