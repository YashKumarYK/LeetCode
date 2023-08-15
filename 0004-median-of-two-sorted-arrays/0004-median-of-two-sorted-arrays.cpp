class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //approach1-> merging logic without the use of resulting array
        int n = nums1.size();
        int m = nums2.size();
        int idx1= (n+m)/2;
        int idx2 = idx1-1;
        int cnt =0;
        int i=0;
        int j=0;
        int el1=INT_MIN;
        int el2=INT_MIN;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                if(cnt==idx1) el1 = nums1[i];
                if(cnt==idx2) el2 = nums1[i];
                cnt++;
                i++;
            }else{
                if(cnt==idx1) el1 = nums2[j];
                if(cnt==idx2) el2 = nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<n){
            if(cnt==idx1) el1 = nums1[i];
            if(cnt==idx2) el2 = nums1[i];
            cnt++;
            i++;
        }
        while(j<m){
            if(cnt==idx1) el1 = nums2[j];
            if(cnt==idx2) el2 = nums2[j];
            cnt++;
            j++;
        }
        if((m+n)%2) return el1;
        return (double) (el1+el2)/2;
    }
};