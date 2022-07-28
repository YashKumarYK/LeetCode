class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> v(prices.size());
        stack<int> s;
        s.push(0);
        for(int i = prices.size()-1; i >=0 ; i --){
            if(s.top()==0) {
                v[i] = prices[i];
            }
            else if(s.top()!=0 && s.top()<=prices[i]){
                v[i] =prices[i] - s.top();
            }
            else if(s.top()!=0 && s.top () >prices[i]){
                while(s.top()!=0 && s.top () >prices[i]){
                    s.pop();
                }
                if(s.top()==0){
                    v[i] = prices[i];
                }
                if(s.top()<=prices[i]){
                    v[i] = prices[i] -s.top();
                }
            }
            s.push(prices[i]);
        }
        return v;
    }
};