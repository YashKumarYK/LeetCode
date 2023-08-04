class Solution {
public:

    int countPairs(vector<int> &nums, int start, int end){
        int mid = start +(end-start)/2;
        int left = start;
        int right = mid+1;
        int cnt=0;
        while( left<=mid){
            while(right<=end && nums[left]> 2*(long long) nums[right]){
                right++;
            }
            cnt += (right-(mid+1));
            left++;
        }
        return cnt;
    }
    void mergeSortedArrays(vector<int> &nums, int start, int end){
        int mid = start+ (end-start)/2;
        int left = start;
        int right = mid+1;
        vector<int> temp;
        while(left<=mid && right <= end){
            if(nums[left]>= nums[right]){
                temp.push_back(nums[right]);
                right++;
            }else{
                temp.push_back(nums[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=end){
            temp.push_back(nums[right++]);
        }

        // overwriting the values to the nums 
        int k = 0;
        for(int i = start; i <= end; i++){
            nums[i] = temp[k];
            k++;
        }
    }

    int mergeSort(vector<int> &nums, int start, int end){
        //base condition
        if(start>=end) return 0; // single element

        int mid = start + (end-start)/2;
        
        int cnt =0;
        // apply recursion on both the halves
        //left part
        cnt+=mergeSort(nums, start, mid);

        //right part
        cnt+=mergeSort(nums, mid+1, end);

        cnt+= countPairs(nums, start, end);
        //merge two sorted array
        mergeSortedArrays(nums, start, end);   
        
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);   
    }
};