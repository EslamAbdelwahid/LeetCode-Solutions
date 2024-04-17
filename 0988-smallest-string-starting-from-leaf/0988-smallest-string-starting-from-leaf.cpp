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
    string smallestFromLeaf(TreeNode* root) {
        string ans , s;
        char c = 'a';
        c += (root->val);
        s += c;
        dfs(root, s, ans);
        return ans ;
    }
    void dfs(TreeNode* root, string s, string &ans){
        if(!root->left && !root->right){
            string t = s;
            reverse(t.begin(), t.end());
            cout << t << "\n";
            if(!ans.size()) ans = t;
            else ans = min(ans, t);
            return ;
        }
        if(root->left) {
            char c = 'a';
            c += (root->left->val);
            dfs(root->left,s + c , ans);
        }
        if(root->right){
            char c = 'a';
            c += (root->right->val);
            dfs(root->right, s + c, ans);
        }
        
    }
};