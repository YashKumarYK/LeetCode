class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore's voting algorithm
        int cnt =0;
        int el;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                el = nums[i];
            }
            if(el== nums[i]){
                cnt++;
            }else{
                cnt--;
            }
        }
        return el;
    }
};

/*
note -> for an subarray whose cnt=0 that means 
        the frequency of the ele is equal to the 
        sum of frequencies of all the other element
        hence that subarray would not have the majority element
*/
