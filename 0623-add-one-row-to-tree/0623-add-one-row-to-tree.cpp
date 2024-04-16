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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth==1){
            TreeNode* ptr=new TreeNode(val);
            ptr->left=root;
            return ptr;
        }
        depth -= 2;
        queue<TreeNode*> q;
        unordered_map < TreeNode*, bool > vis;
        q.push(root);
        while(q.size() && depth){
            int sz = q.size();
            while(sz--){
                auto u = q.front(); q.pop();
                if(vis[u]) continue;
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            --depth;
        }
        while(q.size()){
            auto node = q.front(); q.pop();
        TreeNode* node1 = new TreeNode(val);
        TreeNode* node2 = new TreeNode(val);
        TreeNode* L = nullptr;
        TreeNode* R = nullptr;
        if(node->left){
            L = node->left;
        }
        if(node->right){
            R = node->right;
        }
        node1->left = L;
        node2->right = R;
        node->left = node1;
        node->right = node2;
        }
        return root;
    }
};