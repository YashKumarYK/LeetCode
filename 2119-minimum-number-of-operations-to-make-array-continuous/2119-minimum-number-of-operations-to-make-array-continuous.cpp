class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        
        set<int> st(nums.begin(), nums.end());
        vector<int> uniqueNums;
        for (int num : st) {
            uniqueNums.push_back(num);
        }
        int visited = 0;
        for (int mi = 0; mi < uniqueNums.size(); mi++) {
            while (visited < uniqueNums.size() && uniqueNums[visited] < uniqueNums[mi] + n) {
                visited++;
            }
            
            int subAns = visited - mi;
            ans = min(ans, n - subAns);
        }
        
        return ans;
    }
};


// [1,2,2,3,3,3,4,5,6]
// [1,2,3,4,5,6,7,8,9]


// 1st -> total num of element same
// 2nd -> if(max==min){
// total numof elements
// }
// else +1;