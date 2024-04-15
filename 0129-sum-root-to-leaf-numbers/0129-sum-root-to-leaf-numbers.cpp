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
        dfs(root, to_string(root->val), ans);
        return ans ;
    }
    void dfs(TreeNode* root, string s, int &ans){
        if(!root->left && !root->right){
            ans += stoi(s);
        }
        if(root->left) dfs(root->left, s + to_string(root->left->val), ans);
        if(root->right) dfs(root->right, s + to_string(root->right->val), ans);
    }
};