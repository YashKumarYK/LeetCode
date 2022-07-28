class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> v;
        stack<int> s;
        s.push(0);
        for(int i = prices.size()-1; i >=0 ; i --){
            if(s.top()==0) {
                v.push_back(prices[i]);
            }
            else if(s.top()!=0 && s.top()<=prices[i]){
                v.push_back(prices[i] - s.top());
            }
            else if(s.top()!=0 && s.top () >prices[i]){
                while(s.top()!=0 && s.top () >prices[i]){
                    s.pop();
                }
                if(s.top()==0){
                    v.push_back(prices[i]);
                }
                else if(s.top()<=prices[i]){
                    v.push_back(prices[i] -s.top());
                }
            }
            s.push(prices[i]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};