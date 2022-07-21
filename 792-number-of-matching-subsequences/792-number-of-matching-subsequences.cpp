class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        
        //storing the indices of character in a vector using a map
        for(int i=0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        
        int count = 0;
        //traversing the words vector
        for( auto curr: words){
            
            int latest =-1;
            for( int i=0; i<curr.size(); i++){
                //finding the upper bound of latest indices 
                auto it = upper_bound( mp[curr[i]].begin(), mp[curr[i]].end(), latest);
                
                if( it== mp[curr[i]].end()) break;
                
                if( i== curr.size()-1) count++;
                latest = *it;
            }
        }
        return count;
    }
};