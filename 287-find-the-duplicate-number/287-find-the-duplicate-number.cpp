class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //appproach #1 sorting
        //approach #2 using set 
        // set<int> s;
        // for( auto i: nums){
        //     if( s.count(i)){
        //         return i;
        //     }
        //     s.insert(i);
        // }
        // return -1;
        
        //optimal approach - two pointer fast and slow
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow= nums[slow];
            fast = nums[nums[fast]];
        }while( slow!=fast);
        
        fast = nums[0];
        while(fast!= slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};