class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26, 0);
        for( int i=0; i<s.size(); ++i){
            int j = s[i]-'a';
            count[j]++;
        }
        
        vector<int> num(10,0);
        //unique letters
        num[0] = count['z'-'a'];
        num[2] = count['w'-'a'];
        num[4] = count['u'-'a'];
        num[6] = count['x'-'a'];
        num[8] = count['g'-'a'];
        
        //derived letters
        num[1]=count['o'-'a'] - num[0]-num[4]-num[2];
        num[3]=count['h'-'a'] - num[8];
        num[5]=count['f'-'a'] - num[4];
        num[7]=count['s'-'a'] - num[6];
        num[9]=count['i'-'a'] - num[6]- num[8]-num[5];
        
        string ans;
        for( int i=0; i<=9; i++){
            while(num[i]>0){
                ans.push_back(i+'0');
                num[i]--;
            }
        }
        return ans;
    }
};