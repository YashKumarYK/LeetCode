/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* findNode( TreeNode* root, TreeNode* target, map<TreeNode* , TreeNode*> &mp){
        if( root==NULL) return NULL;
        queue<TreeNode*> q;
        q.push( root);
        mp[root]= NULL;
        TreeNode* res = NULL;
        while( !q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            if(front->val == target->val){
                res =front;
            }
            
            if( front->left){
                q.push( front->left);
                mp[front->left] = front;
            }
            if( front->right){
                q.push( front->right);
                mp[front->right]= front;
            }
        }
        return res;
    }
    
    void bfs( TreeNode* node, map<TreeNode*, TreeNode*> &mp, vector<int> &ans, int k){
        map<TreeNode*, bool> vis;
        vis[node]= true;
        queue<TreeNode*> q;
        q.push( node);
        
        while( !q.empty()){
            int size = q.size();
            bool flag =0;
            for( int i=0; i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left && !vis[front->left]){
                    vis[front->left] = true;
                    q.push(front->left);
                    flag =1;
                    if( k==1){
                        ans.push_back( front->left->val);
                    }
                }
                if( front->right && !vis[front->right]){
                    vis[front->right] = true;
                    q.push( front->right);
                    flag=1;
                    if( k==1){
                        ans.push_back(front->right->val);
                    }
                }
                
                if( mp[front] && !vis[mp[front]]){
                    vis[mp[front]]= true;
                    q.push(mp[front]);
                    flag =1;
                    if( k==1) ans.push_back(mp[front]->val);
                }
            }
            if( flag ==1) k--;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> ptc;
        TreeNode* node = findNode( root, target, ptc);
        if( k==0) return {node->val};
        vector<int> ans;
        bfs( node, ptc, ans, k);
        return ans;
    }
};