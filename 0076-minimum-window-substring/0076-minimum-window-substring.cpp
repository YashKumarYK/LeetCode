class Solution {
public:
    string minWindow(string s, string t) {
        //map to count the occurence of character in t
        unordered_map<char, int> mp;
        for( int i=0; i<t.length(); i++){
            mp[t[i]]++;
        }
        int i=0;
        int j=0;
        int maxI =-1;
        int maxJ = -1;
        int maxLength =INT_MAX;
        int mpsize=mp.size();
        while( j<s.size()){
            //calculation and if character present in the map reduce its count and if the count is zero reduce the map size 
            if( mp.find(s[j]) !=mp.end()){
                mp[s[j]]--;
                if( mp[s[j]] == 0){
                    mpsize --;
                }  
            }
            
            //if map size ==0 then we probably got our candidate for the ans
            if(mpsize==0){
                if( maxLength > j-i+1){
                    maxLength = j-i+1;
                    maxI = i;
                    maxJ = j;
                }
                
                //checking for the better ans if present
                while( mpsize == 0){
                    if( mp.find(s[i]) == mp.end()){
                        i++;
                        if( maxLength > j-i+1){
                            maxLength = j-i+1;
                            maxI = i;
                            maxJ = j;
                        }
                    }
                    
                    else{
                        mp[s[i]]++;
                        if( mp[s[i]]<=0){
                            i++;
                            if( maxLength > j-i+1){
                                maxLength = j-i+1;
                                maxI = i;
                                maxJ = j;
                            }
                        }
                        
                        else if( mp[s[i]] > 0){
                            i++;
                            mpsize++;
                        }
                        
                    }
                }
            }         
            
            j++;
        }
        string ans = "";
        if(!(maxI ==-1 && maxJ ==-1)){
            for( int i= maxI ; i<= maxJ ; i++){
                ans.push_back( s[i]);
            }
        }
        return ans;
    }
};