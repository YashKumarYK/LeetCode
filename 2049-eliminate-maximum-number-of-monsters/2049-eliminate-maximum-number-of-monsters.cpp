class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        for(int i=0;i<n;i++){
            dist[i] = ceil((double)dist[i]*1./ speed[i]);
            
        }
        sort(dist.begin(), dist.end());
        int cnt =1;

        int time = 0;
        for(int i=0; i<n; i++){
           if(time < dist[i]) time++;
           else return time;
        }
        return time;
    }
};