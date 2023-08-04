class Solution {
public:

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

    void mergeSort(vector<int> &nums, int start, int end){
        //base condition
        if(start>=end) return; // single element

        int mid = start + (end-start)/2;

        // apply recursion on both the halves
        //left part
        mergeSort(nums, start, mid);

        //right part
        mergeSort(nums, mid+1, end);

        //merge two sorted array
        mergeSortedArrays(nums, start, end);   
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};

// [1,2,5,3,4,6]