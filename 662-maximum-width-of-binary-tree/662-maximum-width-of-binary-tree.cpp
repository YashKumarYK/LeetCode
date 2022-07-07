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
    int widthOfBinaryTree(TreeNode* root) {
        if( root==NULL){
            return 0;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        int len = 0;
        while( !q.empty()){
            
            int size = q.size();
            int mini = q.front().second;
            int first, last;
            for( int i=0; i<size; i++){
                
                pair<TreeNode*, int> front = q.front();
                q.pop();
                TreeNode* frontNode= front.first;
                int hd = front.second-mini;
                
                if( i ==0) first = hd;
                if( i== size-1) last = hd;
                if( frontNode->left){
                    q.push({frontNode->left,(long long)2*hd+1});
                    
                }
                if( frontNode->right){
                    q.push({ frontNode->right,(long long)2*hd+2});
                }
            }

            len = max( len, last - first+1);
        }
        return len;
    }
};   