#include<bits/stdc++.h>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // distanct -> [ map-> lvl, mutiset]
       map<int, map<int, multiset<int>>> mp;
       queue<pair<TreeNode*, int>> q;
       q.push({root, 0});
        int lvl = 0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* front=q.front().first;
                int dis=q.front().second;
                q.pop();
                
                mp[dis][lvl].insert(front->val);

                if(front->left) 
                {
                    q.push({front->left,dis-1});
                }
                if(front->right) 
                {
                    q.push({front->right,dis+1});
                }
            }
            lvl++;
        }
        vector<vector<int>> ans;
        for(auto i : mp){
            vector<int>v;
            for(auto j:i.second){
                for(auto g : j.second)
                v.push_back(g);
            }
            ans.push_back(v);
        }
        return ans;

    }
};