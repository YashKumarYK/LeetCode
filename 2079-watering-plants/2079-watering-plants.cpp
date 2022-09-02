class Solution {
public:
    int wateringPlants(vector<int>& p, int c) {
        int n = p.size();
        int curr=c;
        int steps=0;
        for( int i=0; i<n; ++i){
            if(curr<p[i]){
                steps += 2*i;
                curr= c;
            }
            steps++;
            curr -= p[i];
            
        }
        return steps;
    }
};