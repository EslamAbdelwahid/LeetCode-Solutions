class Solution {
public:
    vector<int> dp, cnt;
    vector<vector<int>>adj;
    int nodes ;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        nodes = n;
        dp = cnt = vector<int>(n);
        dfs1(0, -1);
        dfs2(0, -1);
        return dp;
    }
    void dfs1(int u, int par){
        for(auto &v : adj[u]){
            if(v != par){
                dfs1(v, u);
                cnt[u] += cnt[v];
                dp[u] += dp[v] + cnt[v];
            }
        }
        cnt[u]++;
    }
    void dfs2(int u, int par){
        for(auto &v  :adj[u]){
            if(v != par){
                dp[v] = dp[u] + (nodes - cnt[v]) - cnt[v];
                dfs2(v,  u);
            }
        }
    }
};