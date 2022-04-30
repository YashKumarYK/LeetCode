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
    // int height(TreeNode* root){
    //     if(root ==NULL) return 0;
    //     else{
    //         int left = height(root->left);
    //         int right = height(root-> right);
    //         int ans = max(left ,right) +1;
    //         return ans;
    //     }
    // }
    pair<int,int> fast_dia(TreeNode* root){
        if( root==NULL) {
            pair<int, int> p = make_pair(0,0);
            return p;
        };
        pair<int, int> left = fast_dia(root->left);
        pair<int,int > right = fast_dia(root-> right);
        
        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second ;
        
        pair<int, int> ans;
        ans.first = max( opt1, max(opt2, opt3));
        ans.second = max(left.second, right.second)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
//         if( root ==NULL) return 0;
//         else{
//             int opt1 = diameterOfBinaryTree(root->left);
//             int opt2 = diameterOfBinaryTree(root-> right);
//             int opt3 = height( root->left) + height(root->right) ;
//             int ans = max(opt1, max(opt2, opt3));
//             return ans ;
            
//         }
        return fast_dia(root).first;
    }
};