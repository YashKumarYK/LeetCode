class Solution {
public:
    bool isValid(vector<int> &b, int m, int k, int days){
        int cnt=0;
        int totalBouquets=0;
        // cout<<days<<":";
        for(int i=0;i<b.size();++i){
            if(b[i]<=days){
                cnt++;
                if(cnt ==k){
                    totalBouquets++;
                    cnt =0;
                }
            }else{
                cnt =0;
            }
        }
        // cout<<totalBouquets<<endl;
        return totalBouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n< (long long) m*k) return -1;
        int s=0;
        int e=*max_element(bloomDay.begin(), bloomDay.end());
        int ans =-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isValid(bloomDay, m, k , mid)){
                ans = mid;
                e = mid-1;
            }else{
                s= mid+1;
            }
        }
        return ans;
    }
};

// k adjacent flower to make a bouquets
// minimum days to make m bouquets
// minimum days to make m*k flowers;
