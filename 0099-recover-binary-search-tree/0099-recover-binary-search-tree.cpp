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
    TreeNode* prev,*first, *mid, *second;
    void inorder(TreeNode* &root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL && prev->val > root->val){
            if(first==NULL){
                first = prev;
                mid = root;
            }else{
                second = root;
            }
        }

        prev= root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev=first=mid=second =NULL;
        inorder(root);

        if(first&&second) swap(first->val, second->val);
        else if(first&&mid) swap(first->val, mid->val);
    }
};