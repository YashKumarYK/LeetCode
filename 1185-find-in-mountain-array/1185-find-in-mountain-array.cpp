/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &arr){
        int s = 0;
        int e = arr.length()-1;
        while(s<e){
            int m = s+(e-s)/2;
            if(arr.get(m)<arr.get(m+1)){
                s= m+1;
            }else{
                e= m;
            }
        }
        return e;
    }
    
    
    int BS(int target, MountainArray &arr, int s, int e){
        while(s<=e){
            int m = s+(e-s)/2;
            if(arr.get(m)==target){
                return m;
            }else if(arr.get(m)<target){
                s = m+1;
            }else{
                e = m-1;
            }
        }
        return -1;
    }

    int RBS(int target, MountainArray &arr, int s, int e){
        while(s<=e){
            int m = s+(e-s)/2;
            if(arr.get(m)==target){
                return m;
            }else if(arr.get(m)>target){
                s = m+1;
            }else{
                e = m-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int p = findPeak(arr);
        cout<<p;
        int ans = BS(target, arr, 0, p);
        
        if( ans == -1){
            return RBS(target,arr, p+1, n-1);
        }
        return ans;
    }
};