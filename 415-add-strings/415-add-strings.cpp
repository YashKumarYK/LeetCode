class Solution {
public:
    string addStrings(string v1, string v2) {
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        
        if( v1.size()==0) return v2;
        if( v2.size()==0) return v1;
        string v;
        int carry =0;
        int sum, val;
        int i=0, j=0;
        while( i<v1.size() || j<v2.size() || carry != 0){
            int n1 =0, n2 =0;
            if( i<v1.size())
                n1 = v1[i]-'0';
            
            if( j<v2.size())
                n2 =v2[j]-'0';
            
            sum = carry+ n1+n2;
            val = sum%10;
            
            v.push_back(val+'0');
            carry = sum/10;
            
            if( i<v1.size()) i++;
            if( j<v2.size()) j++;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};