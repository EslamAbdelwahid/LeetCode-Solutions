class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ans;
        for(int i = 0;i <= n - 3;++i){
            vector<int> v;
            for(int j = 0;j <= n - 3;++j){
                int mx = 0;
                for(int r = i;r - i < 3;++r){
                    for(int c = j;c - j < 3;++c){
                        mx = max(mx, grid[r][c]);
                    }
                }
                v.push_back(mx);
            }
            ans.push_back(v);
        }
        return ans ;
    }
};