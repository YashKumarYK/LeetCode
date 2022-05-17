class node{
    public:
    int val;
    int row;
    int col;
    node(int data, int r, int c){
        val = data;
        row= r;
        col = c;
    }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->val > b->val;
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*, vector<node*>, compare> minHeap;
        
        int mini =10000000, maxi = -10000000;
        
        int k = nums.size();
        
        //inserting the first elements of k list
        for( int i=0; i<nums.size(); i++){
            int element = nums[i][0];
            mini  = min( element, mini);
            maxi = max( element, maxi);
            //inserting 

            node* temp = new node(nums[i][0],i,0);
            minHeap.push(temp);
        }
        
        int start =mini, end = maxi;
        
        while( !minHeap.empty()){
            
            node* temp = minHeap.top();
            minHeap.pop();
            
            mini = temp->val;
            
            //range or answer updating
            if(maxi- mini < end-start){
                start= mini;
                end = maxi;
            }
            
            // checking the existence of next element
            
            if( temp->col+1 < nums[temp->row].size()){
                maxi = max( maxi, nums[temp->row][temp->col+1]);
                minHeap.push(new node(nums[temp->row][temp->col+1], temp->row, temp->col+1));
            }
            else{
                break;
            }
        }
        return {start, end};
    }
};