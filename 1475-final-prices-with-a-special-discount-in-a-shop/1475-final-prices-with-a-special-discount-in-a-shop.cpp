class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        s.push(0);
        vector<int> ans( prices.size(),0);
        for( int i=prices.size()-1; i>=0; --i){
            while( s.top()!=0 && s.top()>prices[i]){
                s.pop();
            }
            ans[i]= prices[i]-s.top();
            s.push(prices[i]);
        }
        return ans;
    }
};