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
//     void inorder( TreeNode* root, vector<int> &v){
//         if( root== NULL){
//             return;
//         }
        
//         if(root->left)
//             inorder(root->left, v);
//         v.push_back(root->val);
//         if( root->right)
//             inorder(root->right,v);
//     }
    
    bool isBST( TreeNode* root, long minVal, long maxVal){
        if( root == NULL){
            return true;
        }
        if( root->val > minVal && root->val< maxVal){
            bool left = isBST( root->left, minVal, root->val);
            bool right = isBST( root->right, root->val, maxVal);
            return (left && right);
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        
        // approach-1 using inorder traversal
        // vector<int> v;
        // inorder(root, v);
        // for(int i=0; i<v.size()-1; i++){
        //     if( v[i]>= v[i+1]){
        //         return false;
        //     }
        // }
        // return true;
        
        //approach2 using recursion
        if (root->left ==NULL && root->right==NULL)
            return true;
        bool ans = isBST(root, LONG_MIN, LONG_MAX);
        return ans;
        
    }
};