class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.size();
        vector<int> come(n+1, 0);
        vector<int> nocome(n+1, 0);
        for(int i=0;i<n;i++){
            int c1 =0;
            if(c[i]=='N') c1 = 1;
            nocome[i+1]= nocome[i]+ c1;
            
            int c2 =0;
            if(c[n-i-1]=='Y') c2=1;     
            come[n-i-1] = come[n-i]+ c2;

        }
        int mini = INT_MAX;
        int ind =0;
        for(int i=0;i<n+1;i++){
            if(mini > come[i]+nocome[i]){
                mini = come[i]+ nocome[i];
                ind = i;
            }
        }
        return ind;

    }
};