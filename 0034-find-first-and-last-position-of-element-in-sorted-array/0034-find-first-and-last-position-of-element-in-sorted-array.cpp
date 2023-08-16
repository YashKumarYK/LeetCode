class Solution {
public:
    int first( vector<int> &arr, int n, int x){
        int s = 0;
        int e = n-1;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==x){
                ans = mid;
                e = mid-1;
            }else if(arr[mid]>x){
                e= mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
    int last(vector<int> &arr, int n, int x){
        int s = 0;
        int e = n-1;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==x){
                ans = mid;
                s= mid+1;
            }
            else if(arr[mid]<x){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstOcc = first(nums, n, target);
        if(firstOcc==-1) return {-1,-1};
        int lastOcc = last(nums, n, target);

        return {firstOcc, lastOcc};
    }
};