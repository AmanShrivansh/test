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
    vector<int>solve(TreeNode* root){
        if(root==NULL)return {0,0};
        
        vector<int>left = solve(root->left);
        vector<int>right = solve(root->right);
        
        vector<int>subans(2,0);
        
        subans[0] = max(left[0],left[1]) + max(right[0],right[1]);
        subans[1] = root->val + left[0] + right[0];
        
        return subans;
        
        
        
    }
    
    
    
    
    int rob(TreeNode* root) {
         vector<int>ans = solve(root);
         return max(ans[0],ans[1]);
    }
};