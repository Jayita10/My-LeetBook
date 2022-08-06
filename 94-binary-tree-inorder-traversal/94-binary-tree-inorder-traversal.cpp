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
//     void inorder(TreeNode* root, vector<int>& ans){
//         if(root == NULL) return;
        
//         if(root->left) inorder(root->left, ans);
//         ans.push_back(root->val);
//         if(root->right) inorder(root->right, ans);
//     }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //inorder(root, ans);
        
        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while(true){
            
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            
            else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                
                ans.push_back(node->val);
                node = node->right;
            }
        }
        
        return ans;
    }
};