class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1=0,cnt2=0;
        int el1, el2;
        for(auto i: nums){
            if(cnt1==0 && i!= el2){
                el1= i;
            }
            else if(cnt2==0 && i!= el1){
                el2=i;
            }

            if(el1==i) cnt1++;
            else if(el2==i) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(auto i: nums){
            if(i==el1) cnt1++;
            if(i==el2) cnt2++;
        }
        vector<int> ans;
        if(cnt1>n/3) ans.push_back(el1);
        if(cnt2>n/3) ans.push_back(el2);
        return ans;
    }
};