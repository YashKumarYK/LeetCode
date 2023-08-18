class Solution {
public:
    bool condition(vector<int> &weights, int days, int wc){
        long long totalWeight=0;
        int day=1;
        for( auto &w: weights){
            if(totalWeight+w <= wc){
                totalWeight+= w;
            }else{
                day++;
                if(day>days || w>wc) return false;
                totalWeight= w;
                
            }
        }
        return  day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = 0;
        int e = accumulate(weights.begin(), weights.end(),0);
        long long ans =0;
        while(s<=e){
            int m = s+(e-s)/2;
            
            if(condition(weights, days, m)){
                ans = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }
        return ans;
    }
};