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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1;i < preorder.size();++i){
            build(root, preorder[i]);
        }
        return root;
    }
    void build(TreeNode* cur, int val){
        if(cur->val > val){
            if(!cur->left) cur->left = new TreeNode(val);
            else build(cur->left, val);
        }else{
            if(!cur->right) cur->right =new TreeNode(val);
            else build(cur->right, val);
        }
    }
};