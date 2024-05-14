class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int ans = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        function<void(int,int,int)> dfs=[&](int i, int j,int sum){
            vis[i][j] = 1;
            ans = max(ans, sum);
            for(int k = 0;k < 4;++k){
                int ni = i + dx[k], nj = j + dy[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] && !vis[ni][nj]){
                    dfs(ni, nj, sum + grid[ni][nj]);
                }
            }
            vis[i][j] = 0;
        };
         for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(grid[i][j]){
                    dfs(i, j, grid[i][j]);
                }
            }
        }
        return ans ;
    }
};