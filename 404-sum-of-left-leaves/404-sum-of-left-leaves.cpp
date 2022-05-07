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
    // bool isleaf(TreeNode* root){
    //     if( root==NULL) return false;
    //     if( root->left ==NULL &&  root->right == NULL){
    //         return true;
    //     }
    //     return false;
    // }
    int sumOfLeftLeaves(TreeNode* root) {
//         if(root== NULL){
//             return 0;
//         }
        
//         if(isleaf(root->left)){
//             return root->left->val + sumOfLeftLeaves(root->right);
//         }
//         else{
//             return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
//         }
        queue<TreeNode*> q;
        if (root==NULL) return false;
        q.push(root);
        int sum = 0;
        while( !q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if( front->left !=NULL && front->left->left ==NULL && front->left->right ==NULL){
                sum = sum+ front->left->val;
            }
            if( front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        return sum;
    }
};