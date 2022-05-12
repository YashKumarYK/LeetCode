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
    void inorder( TreeNode* root, vector<int> &v){
        if( root== NULL){
            return;
        }
        if(root->left) inorder(root->left, v);
        v.push_back(root->val);
        if(root-> right) inorder(root->right, v);
    }
    
    TreeNode* buildBST( int s, int e, vector<int> &v){
        if( s>e) return NULL;
        
        int mid = s+(e-s)/2;
        TreeNode* temp = new TreeNode( v[mid]);
        temp->right = buildBST(mid+1, e, v);
        temp->left = buildBST(s, mid-1,v);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return buildBST(0, v.size()-1, v);
        
    }
};