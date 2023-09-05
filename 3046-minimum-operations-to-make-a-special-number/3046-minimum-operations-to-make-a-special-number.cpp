class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        bool zero = false;
        bool five = false;

        for(int i=n-1;i>=0;i--){
            char ch = num[i];
            if(zero && (ch=='0' ||ch=='5'))  return n-2-i;
            if(five && (ch=='7'|| ch=='2'))  return n-2-i;
            if(ch=='0') zero= true;
            if(ch=='5') five = true;
        }
        return zero?n-1: n;
    }
};