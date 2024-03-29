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
    
//     void preOrder(TreeNode* root, vector<int>& ans){
//         if(root == NULL) return;
        
//         ans.push_back(root->val);
//         if(root->left) preOrder(root->left, ans);
//         if(root->right) preOrder(root->right, ans);
//     }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        //preOrder(root, ans);  
        if(root == NULL) return ans;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return ans;
    }
};