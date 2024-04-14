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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans ;
    }
    void dfs(TreeNode* root, int isleft, int &sum){
        if(!root->left && !root->right && isleft) sum += root->val;
        if(root->left) dfs(root->left, 1, sum);
        if(root->right) dfs(root->right, 0, sum);
    }
};