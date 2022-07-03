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
    
    int travel( TreeNode* root){
        if( root == NULL){
            return 0;
        }
        if( root->left==NULL && root->right !=NULL){
            return 1+ travel(root->right);
        }
        if( root->right ==NULL && root->left !=NULL){
            return 1+ travel(root->left);
        }
        
        int left = travel( root->left);
        int right = travel( root->right);
        
        return min( left, right)+1;
    }
    int minDepth(TreeNode* root) {
        if( root== NULL ) return 0;
        return travel( root);
    }
};