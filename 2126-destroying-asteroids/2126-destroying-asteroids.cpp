class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        // int sum = accumulate( a.begin(), a.end(),0);
        // int maxi = * max_element( a.begin(), a.end());
        
        // if( maxi > sum - maxi +mass) return false;
        long long sum = mass;
        sort( a.begin(), a.end());
        for( int i=0; i<a.size(); i++){
            if( sum >= a[i]){
                sum += a[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};