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
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        q.push({root,{0,0}});
        while(!q.empty()){
            auto pair = q.front();
            q.pop();
            TreeNode* node = pair.first;
            int v = pair.second.first;
            int l = pair.second.second;
            
            m[v][l].insert(node->val);
            
            if(node->left)
                q.push({node->left,{v-1,l+1}});
            if(node->right)
                q.push({node->right,{v+1,l+1}});
        }
        
        vector<vector<int>> ans;
        for(auto p:m){
            vector<int> val;
            for(auto q: p.second){
                val.insert(val.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(val);
        }
        return ans;
    }
};