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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, root->val , ans);
        return ans ;
    }
    void dfs(TreeNode* root, int num, int &ans){
        if(!root->left && !root->right){
            ans += num;
        }
        if(root->left) dfs(root->left, num * 10 + (root->left->val) , ans);
        if(root->right) dfs(root->right,num * 10 + (root->right->val) , ans);
    }
};