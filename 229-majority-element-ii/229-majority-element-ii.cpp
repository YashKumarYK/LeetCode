class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 =0, cnt2=0;
        int n1=INT_MIN, n2= INT_MIN;
        for(auto ele: nums){
            if(ele == n1){
                cnt1++;
            }
            else if(ele ==n2){
                cnt2++;
            }
            else if( cnt1==0){
                n1=ele;
                cnt1=1;
            }
            else if( cnt2==0){
                n2=ele;
                cnt2 =1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> ans;
        cnt1 =0;
        for(auto i:nums){
            if( n1==i) cnt1++;
        }
        
        cnt2 =0;
        for(auto i:nums){
            if( n2==i) cnt2++;
        }
        if (cnt1> nums.size()/3) ans.push_back(n1);
        if(cnt2>nums.size()/3) ans.push_back(n2);
        
        return ans;
        
    }
};