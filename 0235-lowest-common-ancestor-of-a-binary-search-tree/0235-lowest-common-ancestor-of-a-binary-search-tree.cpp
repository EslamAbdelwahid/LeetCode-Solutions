/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = p->val, b = q->val;
        if(a > b) swap(a, b);
        return lca(root, a , b);
    }
    TreeNode* lca(TreeNode* root, int a, int b){

        if(a > root->val && b > root->val){
          return  lca(root->right, a,  b);
        }
        if(a < root->val && b < root->val){
           return lca(root->left , a , b);
        }
        return root;
    }
};