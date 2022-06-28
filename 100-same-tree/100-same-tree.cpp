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
//     void inorder(TreeNode* root, vector<int> &v){
//         if( root ==NULL) return;
        
//         inorder(root->left, v);
//         v.push_back( root->val);
//         inorder(root->right, v);
//     }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p==NULL && q==NULL) return true;
        if( p==NULL || q==NULL) return false;
        // if( p==NULL&& q==NULL) return true;
        
        if( p->val != q->val) return false;
        bool left = isSameTree( p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        
        return left&&right;
    }
};