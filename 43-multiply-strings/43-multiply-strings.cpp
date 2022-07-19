class Solution {
public:
    
    vector<int> add( vector<int> &v1, vector<int> &v2){
        if( v1.size()==0) return v2;
        if( v2.size()==0) return v1;
        vector<int> v;
        int carry =0;
        int sum, val;
        int i=0, j=0;
        while( i<v1.size() || j<v2.size() || carry != 0){
            int n1 =0, n2 =0;
            if( i<v1.size())
                n1 = v1[i];
            
            if( j<v2.size())
                n2 =v2[j];
            
            sum = carry+ n1+n2;
            val = sum%10;
            
            v.push_back(val);
            carry = sum/10;
            
            if( i<v1.size()) ++i;
            if( j<v2.size()) ++j;
        }
        
        return v;
    }
    string multiply(string nums1, string nums2) {
        
        if(nums1=="0" || nums2=="0") return "0";
        
        //reversing the string
        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());
        
        vector<int> v;
        for(int i=0;i<nums1.size(); i++){
            int carry = 0;
            int j =0;
            vector<int> v1(i,0);
            while(j<nums2.size() || carry!=0){
                int val =0;
                
                if(j<nums2.size()) 
                    val =(nums1[i]-'0')*(nums2[j]-'0');
                
                int prod = carry + val;
                int ans = prod%10;
                
                carry = prod/10;
                v1.push_back(ans);            
                if( j<nums2.size()) ++j;
            }
            v = add(v, v1);
        }
        string s="";
        for(int i=v.size()-1; i>=0; --i){
            s.push_back(v[i]+'0');
        }
        return s;
    }
}; 