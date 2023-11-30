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
    vector<vector<int>>ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        dfs(root, 0 , targetSum, path);
        return ans;
    }
    void dfs(TreeNode* root, int sum, int target,vector<int>&path){
        if(!root) return;
        if(!root->left && !root->right){
            if(sum + root->val == target){
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
                return;
            }
        }
        if(root->left){
            path.push_back(root->val);
            dfs(root->left, sum + root->val, target, path);
            path.pop_back();
        }
        if(root->right){
            path.push_back(root->val);
            dfs(root->right, sum + root->val, target, path);
            path.pop_back();
        }
    }
};