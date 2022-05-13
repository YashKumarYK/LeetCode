class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for( int i=0;i<logs.size(); i++){
            if( !s.empty() && logs[i] =="../"){
                s.pop();
            }
            else if(logs[i]=="./" || ( s.empty() && logs[i] =="../"))
                continue;
            else{
                s.push(logs[i]);
            }
        }
        return s.size();
    }
};