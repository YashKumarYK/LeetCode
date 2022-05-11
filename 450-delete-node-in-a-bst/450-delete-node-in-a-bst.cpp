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
    // TreeNode* minval( TreeNode* root){
    //     TreeNode* temp = root;
    //     while( temp->left !=NULL){
    //         temp= temp-> left;
    //     }
    //     return temp;
    // }
    TreeNode* maxval(TreeNode* root){
        TreeNode* temp = root;
        while(temp->right != NULL){
            temp = temp->right;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) \
    {
        if ( root == NULL){
             return NULL;
        }
        
        else if( root->val == key)
        {
            // 0 child
            if( root->left==NULL && root->right== NULL){
                return NULL;
            }
            
            //1 child
            //left child
            
            if(root->left !=NULL && root->right ==NULL){
                TreeNode* temp = root->left; 
                delete root;
                return temp;
            }
            //right child
            if(root->left ==NULL && root->right !=NULL){
                TreeNode* temp = root->right; 
                delete root;
                return temp;
            }
            //2child
            if( root->left !=NULL && root->right !=NULL){
                //option 1
                // int mini = minval( root->right)->val;
                // root->val = mini;
                // root->right = deleteNode(root->right, mini);
                // return root;
                
                //option 2
                int max = maxval(root->left)->val;
                root->val = max;
                root->left = deleteNode(root->left , max);
                return root;
            }
        }
        else if( root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else{
            root->right = deleteNode(root->right, key);
            return root;
        }
        return root;
    }
};