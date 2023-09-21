class Solution {
public:
    bool possible(vector<int>& candies, long long k,int no){
        long long tc=0;
        for(int c:candies){
            tc+=c/no;
        }
        return tc>=k;

    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long start=1;
        long long end=INT_MAX;
        long long ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(possible(candies,k,mid))
            {
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;

    }
};


