class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int  s= INT_MAX;
        int MAXPROF = 0;
        for(int i=0;i<prices.size(); i++){
            s = min(s, prices[i]);
            int maxprofit = prices[i]-s;  
            MAXPROF = max(MAXPROF, maxprofit);
        }
        return MAXPROF;
    }
};


// smallest = min(smallest, prices[])
 
//       7       1        5       3      6     4
// s     7       1        
// m     7-7     1=1
// maxprof => minbuy 
