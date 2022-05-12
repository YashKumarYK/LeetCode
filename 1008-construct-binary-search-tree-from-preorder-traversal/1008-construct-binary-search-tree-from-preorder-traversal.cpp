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
    TreeNode* solve( vector<int>& preorder, int maxi, int mini, int &i){
        if( i>=preorder.size()) return NULL;
        if( preorder[i]>maxi || preorder[i]< mini){
            return NULL;
        }
        
        TreeNode* temp = new TreeNode(preorder[i++]);
        temp->left = solve(preorder, temp->val, mini, i);
        temp->right = solve(preorder, maxi, temp->val, i);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int  mini = INT_MIN;
        int maxi = INT_MAX;
        int i=0;
        return solve(preorder, maxi, mini, i);
    }
};