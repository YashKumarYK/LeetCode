class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s=0; 
        int e= s+1;
        int maxi= 0;
        while( e<prices.size()){
            if (prices[s]< prices[e]){
                maxi= max( prices[e]-prices[s], maxi);
            }
            else{
                s=e;
            }
            e++;
        }
        return maxi;
    }
};