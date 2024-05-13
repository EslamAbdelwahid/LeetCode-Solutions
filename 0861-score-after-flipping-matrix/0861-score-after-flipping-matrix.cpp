class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0;i < n;++i){
            if(grid[i][0] == 0){
                for(int j = 0;j < m;++j) grid[i][j] ^= 1;
            }
        }
        for(int j  = 0;j < m;++j){
            int ones = 0;
            for(int i = 0;i < n;++i){
                ones += grid[i][j];
            }
            int zeros = n - ones;
            if(zeros > ones){
                for(int i = 0;i < n;++i){
                    grid[i][j] ^= 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < n;++i){
            int mask = 0;
            for(int j =0 ;j < m;++j){
                if(grid[i][j]) mask |= (1ll << (m - j - 1));
            }
            ans += mask;
        }
        return ans ;
    }
};