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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        int ret = 1;
        if(!root1 && !root2) return 1;
        if((root1 && !root2) || (!root1 && root2)) return 0;
        if(root1->val != root2->val) return 0;
        bool ch1 = flipEquiv(root1->left, root2->left);
        bool ch2 = flipEquiv(root1->right, root2->right);
        bool ch3 = flipEquiv(root1->left, root2->right);
        bool ch4 = flipEquiv(root1->right, root2->left);
        return ((ch1 && ch2) || (ch3 && ch4));
    }
};