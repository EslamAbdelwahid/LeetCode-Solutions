class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 1) return grid[0][0];
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(), -1));
        int ans = 1e9 ;
        for(int j = 0;j < grid.size();++j){
            ans = min(ans, best(0, j, grid, dp));
        }
        return ans ;
    }
    int best(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i == grid.size()) return 0;
        int &ret = dp[i][j];
        if(~ret) return ret ;
        ret = 1e9 ; 
        for(int k = 0;k < grid[0].size();++k){
            if(j != k){
                ret = min(ret, best(i + 1, k, grid, dp) + grid[i][j]);
            }
        }
        return ret ;
    }
};