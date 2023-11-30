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
    int ans = 0;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root , 0);
        return ans;
    }
    void dfs(TreeNode* root,int num){
        if(!root->left && !root->right){
            num = num * 10 + root->val;
            ans += num;
            return;
        }
        if(root->left) dfs(root->left , num * 10 + root->val);
        if(root->right) dfs(root->right , num * 10 + root->val);
    }
};