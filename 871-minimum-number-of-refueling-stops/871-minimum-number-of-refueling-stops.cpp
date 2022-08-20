class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& station) {
        
        int count=0;
        priority_queue<int> pq;
        int i=0;
        while(target>fuel){
            
            while(i<station.size() and station[i][0]<=fuel){
                pq.push(station[i][1]);
                i++;
            }
            if(pq.empty()){
                return -1;
            }
            fuel+= pq.top();
            count++;
            pq.pop();
        }
        
        return count;
    }
};