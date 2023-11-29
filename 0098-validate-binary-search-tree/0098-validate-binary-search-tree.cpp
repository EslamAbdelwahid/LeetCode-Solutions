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
    bool isValidBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        for(int i = 1;i < nodes.size();++i){
            if(nodes[i] <= nodes[i - 1]) return 0;
        }
        return 1;
    }
    void inorder(TreeNode* root, vector<int>&nodes){
        if(root->left) inorder(root->left, nodes);
        nodes.push_back(root->val);
        if(root->right) inorder(root->right, nodes);
    }
    
};