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
    unordered_map<TreeNode*, TreeNode*> parent;
    void bfs(TreeNode* target, int k , vector<int> & ans){
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        vis[target]=true;
        q.push(target);
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; i++){
                TreeNode* front = q.front();
                q.pop();
                
                if(k==0){
                    ans.push_back(front->val);
                }
                if(front->left !=NULL && vis[front->left]==false){
                    q.push(front->left);
                    vis[front->left]=true;
                }
                if(front->right !=NULL && vis[front->right]==false){
                    q.push(front->right);
                    vis[front->right]=true;
                }

                if(parent[front]!=NULL && vis[parent[front]]==false){
                    q.push(parent[front]);
                    vis[parent[front]]= true;
                }
                cout<<front->val<<"---";
            }
            cout<<endl;
            k--;
        }
    }

    void findNode(TreeNode *root, TreeNode* target){
        parent[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front->left){
                q.push(front->left);
                parent[front->left]= front;
            }
            if(front->right){
                q.push(front->right);
                parent[front->right]= front;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        findNode(root, target);
        vector<int> ans;
        bfs(target, k, ans);
        return ans;
    }
};