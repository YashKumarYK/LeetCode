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
    void solve( TreeNode* root, int ans, vector<int> &v ){
    //base case
        if( root==NULL){
            
            return;
        }
        ans= root->val +ans*10;
        if( root->left ==NULL && root->right ==NULL ){
            v.push_back(ans);
        }
        
        solve( root->left, ans, v );
        solve( root->right, ans, v );
    }
    int sumNumbers(TreeNode* root) {
        int ans =0;
        int sum =0;
        vector<int> v;
        solve(root, ans, v);
        for(int i =0; i<v.size(); i++){
            sum += v[i];
        }
        return sum;
        
    }
};