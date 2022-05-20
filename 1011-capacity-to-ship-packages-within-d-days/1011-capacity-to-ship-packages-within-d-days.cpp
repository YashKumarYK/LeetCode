class Solution {
public:
    
    bool ispossible( vector<int> weights, int days,int mid){
        int weightsum =0;
        int daycount =1;
        for(int i=0; i<weights.size(); i++){
            if( weightsum + weights[i] <=mid){
                weightsum += weights[i];
            }
            else{
                daycount++;
                if(daycount > days || weights[i]>mid) return false;
                weightsum = weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(auto i: weights){
            sum = sum+ i;
        }
        
        int s=0; int e=sum;
        int mid = s+(e-s)/2;
        int ans =-1;
        while( s<=e){
            if( ispossible( weights, days, mid)){
                ans = mid; 
                e= mid -1;
            }
            else{
                s = mid+1;
            }
            mid= s+( e-s)/2;
        }
        return ans;
    }
};