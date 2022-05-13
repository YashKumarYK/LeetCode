class Solution {
public:
    int minOperations(vector<string>& logs) {
        //approach 1 - using stack 
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
        
        //approach 2 using pointer
        int count=0;
        for(int i =0; i<logs.size(); i++){
            if( logs[i]== "../"){
                count--;
                if(count<0) count=0;
            }
            else if( logs[i]=="./"){
                continue;
            }
            else{
                count++;
            }
        }
        return count;
    }
};