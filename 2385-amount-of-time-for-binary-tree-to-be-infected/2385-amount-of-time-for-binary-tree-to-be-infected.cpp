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
    TreeNode* mapping( unordered_map<TreeNode*, TreeNode*> &mp, TreeNode* root, int start){
        queue<TreeNode*> q;
        q.push(root);
        mp[root] = NULL;
        TreeNode* srchroot= NULL ;
        while( !q.empty()){
            int size = q.size();
            for( int i=0; i<size; ++i){
                TreeNode* front = q.front();
                q.pop();
                
                if( front->val == start){
                    srchroot = front;
                }
                if( front->left){
                    q.push(front->left);
                    mp[front->left] = front;
                }
                if( front->right){
                    q.push(front->right);
                    mp[front->right] = front;
                }
            }
        }
        return srchroot;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp;
        TreeNode* srch = mapping( mp, root, start);
       
        queue<TreeNode*> q;
        q.push(srch);
        unordered_map<TreeNode*, bool> vis;
        vis[srch]= true;
        int cnt =0;
        while(!q.empty()){
            int size = q.size();
            bool added =  false;
            for( int i=0; i<size; ++i){
                TreeNode* front = q.front();
                q.pop();
                //pushing the parent and left right child in the queue
                //parent
                if( mp[front] && !vis[mp[front]]){
                    q.push(mp[front]);
                    vis[mp[front]] = true;
                    added = true;
                    
                }
                // left
                if( front->left && !vis[front->left]){
                    q.push( front->left);
                    vis[front->left] = true;
                    added = true;
                
                } 
                
                //right
                if( front->right && !vis[front->right]){
                    q.push( front->right);
                    vis[front->right] = true;
                    added = true;
                
                }
            }
            if(added) cnt++;
       
        }
        
        return cnt;
    }
};