class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>>adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int leaf = -1, mx = 0, node = -1;
        for(int i = 0;i < n;++i){
            if(adj[i].size() == 1) leaf = i;
        }
        dfs(leaf, -1, 0, mx, node, adj);
        int start = node;
        dfs(node, -1, 0, mx, leaf, adj);
        int end = leaf;
        vector<int> path, ans ;
        dfs2(start, end, -1, path, ans, adj);;
        if(ans.size() & 1) return {ans[ans.size() / 2]};
        return {ans[ans.size() / 2], ans[ans.size() / 2 - 1]};
    }
    void dfs2(int u, int end, int par, vector<int>&path, vector<int>&ans,vector<vector<int>>&adj){
        path.push_back(u);
        if(u == end){
            ans = path;
            return ;
        }
        for(int &v : adj[u]){
            if(v != par){
                dfs2(v, end, u, path, ans, adj);
            }
        }
        path.pop_back();
    }
    void dfs(int u, int par, int cnt, int  &max_h, int &node,vector<vector<int>>&adj){
        if(cnt > max_h){
            max_h = cnt;
            node = u;
        }
        for(auto &v : adj[u]){
            if(v!=par) dfs(v, u, cnt + 1, max_h, node, adj);
        }
    }
};