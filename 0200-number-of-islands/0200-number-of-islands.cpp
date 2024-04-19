class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1, -1, 0, 0};
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ++ans;
                    dfs(i, j, grid, vis, n, m);
                }
            }
        }
        return ans;
    }
    void dfs(int i, int j, vector<vector<char>>&grid,vector<vector<bool>>&vis,int n,int m){
        vis[i][j] = 1;
        for(int k  = 0;k < 4;++k){
            int ni = dx[k] + i, nj  = j + dy[k];
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && grid[ni][nj] == '1'){
                dfs(ni , nj, grid, vis, n, m);
            }
        }
    }
};