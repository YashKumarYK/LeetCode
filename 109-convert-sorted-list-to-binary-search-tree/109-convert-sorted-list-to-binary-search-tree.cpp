/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildBST( vector<int> &in, int s, int e){
        if( s>e) return NULL;
        
        int mid = s+ (e-s)/2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = buildBST(in, s, mid-1);
        root->right = buildBST(in, mid+1, e);
        return root;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> in;
        ListNode* temp = head;
        while( temp!=NULL){
            in.push_back( temp->val);
            temp= temp->next;
        }
        int s =0; 
        int e= in.size()-1;
        // for( int i=0; i< in.size(); i++){
        //     cout<<in[i]<<endl;
        // }
        TreeNode* ans = buildBST( in, s,e);
        return ans;
    }
};