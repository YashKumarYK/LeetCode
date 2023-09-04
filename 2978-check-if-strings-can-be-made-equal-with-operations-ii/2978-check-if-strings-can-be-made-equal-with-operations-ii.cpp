class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1==s2) return true;
        int n = s2.size();
        //  first method
        // for(int i=0;i<n;i++){
        //     if(s1[i]==s2[i]) continue;
        //     bool possible = false;
        //     for(int j = i; j<n; j= j+2){
        //         if(s1[i]==s2[j]){
        //             swap(s2[i], s2[j]);
        //             possible = true;
        //             break;
        //         }
        //     }
        //     if(!possible) return false;
        // }

        vector<vector<int>> mp(26, vector<int> (2, 0));
        for(int i=0;i<n; i++){
            mp[s1[i]-'a'][i%2]++;
            mp[s2[i]-'a'][i%2]--;
        }

        for(int i=0;i<26; i++){
            if(mp[i][0]!=0 ||  mp[i][1]!=0) return false;
        }
        return true;
    }
   
};