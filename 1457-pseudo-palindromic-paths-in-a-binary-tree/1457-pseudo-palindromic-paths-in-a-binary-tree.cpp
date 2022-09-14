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
    int v[10];
    int count =0;
    void solve( TreeNode* root){
        if( !root) return;
        v[root->val]++;
        if( !root->left && !root->right){
            int t=0;
            for( int i=0; i<10; ++i){
                if( v[i]&1){
                    t++;
                }
            }
            if(t<=1)
                count++;
        }
        
        solve( root->left);
        solve( root->right);
        v[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve( root);
        return count;
    }
};