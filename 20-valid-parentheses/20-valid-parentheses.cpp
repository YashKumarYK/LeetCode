class Solution {
public:
    bool ispossible( char top, char ch){
        if( (top == '{' && ch=='}') || (top =='[' && ch ==']') || (top =='(' &&  ch == ')')){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for( int i=0; i< n; i++){
            char ch = s[i];
            if (ch== '['||ch== '{' || ch=='('){
                st.push(ch);
            }
            
            else if(!st.empty()){
                char top = st.top();
                if( ispossible(top, ch)){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else return false;
        }
        if( st.empty())
            return true;
        return false;
    }
};