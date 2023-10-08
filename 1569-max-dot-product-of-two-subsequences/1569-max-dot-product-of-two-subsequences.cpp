class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int ind1, int ind2, vector<vector<int>> &dp){
        //base cond
        if(ind1==nums1.size() || ind2==nums2.size()) return  -100000;
        //conditions 
        if(dp[ind1][ind2]!= -1) return dp[ind1][ind2];

        //dot prod 

        int onlyThis = nums1[ind1]*nums2[ind2];
        int include = nums1[ind1]*nums2[ind2] + solve(nums1, nums2, ind1+1, ind2+1, dp);

        int exc1 = solve(nums1, nums2, ind1+1, ind2, dp);
        int exc2 = solve(nums1, nums2, ind1, ind2+1, dp);

        return  dp[ind1][ind2]= max({onlyThis, include, exc1, exc2});

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int> (nums2.size()+1, -1));
        return solve(nums1, nums2, 0, 0, dp);
    }
};

