class Solution {
public:

    bool cond(bool z , bool f , char ch){
        if(z && ch=='0') return true;
        if(z && ch=='5') return true;
        if(f && ch=='7') return true;
        if(f && ch=='2') return true;
        return false;
    }
    int minimumOperations(string num) {
        int n = num.size();
        bool zero = false;
        bool five = false;

        for(int i=n-1;i>=0;i--){
            if(cond(zero, five, num[i])){
                return n-2-i;
            }

            if(num[i]=='0') zero= true;
            if(num[i]=='5') five = true;
        }
        if(zero==false){
            return n;
        }
        else{
            return n-1;
        }
    }
};