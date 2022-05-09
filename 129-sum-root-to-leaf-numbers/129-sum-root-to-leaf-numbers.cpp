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
    void solve( TreeNode* root, int ans, int &sum  ){
    //base case
        if( root==NULL){
            return;
        }
        ans= root->val +ans*10;
        if( root->left ==NULL && root->right ==NULL ){
            // v.push_back(ans);
            sum = sum+ans;
        }
        
        solve( root->left, ans, sum );
        solve( root->right, ans, sum );
    }
    int sumNumbers(TreeNode* root) {
        int ans =0;
        int sum =0;
        solve(root, ans, sum);       
        return sum;
        
    }
};