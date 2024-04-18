class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(),0));
        int ans = 0;
        for(int i  = 0;i < grid.size();++i){
            for(int j = 0;j < grid[0].size();++j){
                if(grid[i][j]){
                    dfs(i, j, ans, vis, grid);
                    return ans;
                }
            }
        }
        return ans;
        
    }
    void dfs(int i, int j, int &ans, vector<vector<int>>&vis, vector<vector<int>>&grid){
        vis[i][j] = 1;
        for(int k = 0;k < 4;++k){
            int ni = i + dx[k], nj = j + dy[k];
            if(ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size() ){
                ++ans;
            }else if(!vis[ni][nj]){
                if(!grid[ni][nj]) ++ans;
                else dfs(ni, nj, ans, vis, grid);
            }
        }
    }
};