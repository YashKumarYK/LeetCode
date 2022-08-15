class Solution {
public:
    int m= 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<long long ,long long> mp;
        sort(arr.begin(), arr.end());
        for( int i=0; i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        for( int i=0;i<arr.size(); ++i){
            long long count =0;
            for( int j=0;j<i; ++j){
                
                if( arr[i]%arr[j]==0  &&  mp.find(arr[i]/arr[j])!=mp.end()){
                    count= (count%m + (mp[arr[j]] * mp[arr[i]/arr[j]])%m)%m;
                }
            }
            
            mp[arr[i]] += count%m;
        }
        
        int cnt =0;
        for( auto i: mp){
            cnt= (cnt%m +i.second%m)%m;
        }
        return cnt%m;
    }
};