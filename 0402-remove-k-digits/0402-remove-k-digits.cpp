class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        st.push(num[0]);
        for(int i=1;i<n; i++){
            while( k!=0 && !st.empty() && st.top()>num[i]){
                st.pop();
                k--;
                if(k==0){
                    break;
                }
            }
            st.push(num[i]);
        }
        if(k>=st.size()){
            return "0";
        }

        while(k!=0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans ;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.size()==0) return "0";
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};