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
    int ans = -1e9;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){
        int l = 0, r = 0;
        if(root->left) l += max(0,dfs(root->left));
        if(root->right) r += max(0,dfs(root->right));
        ans = max(ans, l + r + root->val);
        return max(l, r) + root->val;
    }
    
};