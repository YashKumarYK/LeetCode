class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int left =0;
        int right = n-2;
        while(left<=right){
            int mid = left+(right-left)/2;
            if((mid%2==0 && arr[mid]==arr[mid+1])||(mid%2==1 && arr[mid]==arr[mid-1])){ 
                //to ensure that we are on the left side
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return arr[left];
        
    }
};

// before the single element out left half would have the following scenario:
// first instance = even index
// second instance = odd index

//just find the left half, at the end the left
//why right = n-1, because lets consider the array= [1,1,2,2,3,3,4]
//here at the end we find the left appears on the just after the left part;
// to avoid the extra if else condition we consider right = n-2;