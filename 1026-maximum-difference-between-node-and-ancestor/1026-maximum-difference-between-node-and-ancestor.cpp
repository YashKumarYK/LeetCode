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
    
    void solve( TreeNode* &root, int maxi, int mini, int &diff){
        if( root==NULL) return;
        
        mini = min( mini, root->val);
        maxi = max( maxi, root->val);
        diff = max( diff, abs( maxi- mini));
        // traverse through depth
        solve( root->left, maxi, mini, diff);
        solve( root->right, maxi, mini, diff);
        
        
    }
    int maxAncestorDiff(TreeNode* root) {
        if( root ==NULL) return 0;
        int diff =0;
        solve( root, INT_MIN, INT_MAX, diff);
        return diff;
    }
};