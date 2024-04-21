class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1,0 ,0};
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size() ;
        vector<vector<int>>vis(n,vector<int>(m)), ans;
        for(int i = 0; i < n;++i){
            for(int j = 0;j < m;++j){
                if(!vis[i][j] && land[i][j]){
                    pair<int,int> idx = {-1,-1};
                    dfs(i, j, vis, land, idx, n, m);
                    ans.push_back({i, j, idx.first, idx.second}); 
                }
            }
        }
        return ans ;
        
    }
    void dfs(int i, int j, vector<vector<int>>&vis,vector<vector<int>>& land, pair<int,int>&idx, int &n, int &m){
        idx = max(idx, {i, j});
        vis[i][j] = 1;
        for(int k = 0;k < 4;++k){
            int ni = i + dx[k], nj = j + dy[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && land[ni][nj] && !vis[ni][nj]){
                dfs(ni, nj, vis, land, idx, n, m);
            }
        }
    }
};