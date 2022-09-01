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
    
    int count = 0;
        
    int solve(TreeNode* root, int maxi){
        if(!root) return 0;
        
        if(root->val >= maxi){
            count++;
            maxi = root->val;
        }
        solve(root->left, maxi);
        solve(root->right, maxi);
        
        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        return solve(root, INT_MIN);
    }
};