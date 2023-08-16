class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //approach2->BINARY SEARCH
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n =nums1.size();
        int m = nums2.size();
        int k = (n+m+1)/2;
        int low = 0;
        int high = n;

        while(low<=high){
            int cut1 = low+(high-low)/2;
            int cut2 = k-cut1;
            int l1 = cut1==0?INT_MIN: nums1[cut1-1];
            int l2 = cut2==0?INT_MIN: nums2[cut2-1];
            int r1 = cut1==n? INT_MAX: nums1[cut1];
            int r2 = cut2==m? INT_MAX: nums2[cut2];

            //valid condition
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0){
                    return (double)(max(l1,l2)+ min(r1,r2))/2.0;
                }else{
                    return double(max(l1,l2));
                }
            }
            else if(l1>r2){
                //move the cut to the left
                high = cut1-1;
            }else{
                //move the cut to the right
                low = cut1+1;
            }
        }
        return 0.0;
    }
};