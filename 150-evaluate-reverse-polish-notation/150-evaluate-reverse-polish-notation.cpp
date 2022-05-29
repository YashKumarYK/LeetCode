class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n= tokens.size();
        for( int i=0; i<n; i++){
            string ch = tokens[i];
            if( ch == "+" || ch== "/" || ch== "-" || ch=="*"){
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                s.pop();
                
                if(ch== "+") s.push( top1+ top2);
                else if( ch=="-") s.push( top2 -top1);
                else if (ch== "/") s.push( top2/ top1);
                else if(ch=="*")  s.push( top1 * top2);
            }
            else{
                s.push(stoi(ch));
            }
            
        }
        return s.top();
    }
};