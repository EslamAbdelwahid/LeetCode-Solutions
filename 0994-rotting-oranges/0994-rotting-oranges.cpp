class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(grid[i][j] == 2){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int sz = q.size();
        int ans = 0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto [i, j] = q.front();
                q.pop();
                for(int k  = 0;k < 4;++k){
                    int ni = i + dx[k], nj = j + dy[k];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && dist[ni][nj] == -1 && grid[ni][nj] == 1){
                        dist[ni][nj] = dist[i][j] + 1;
                        q.push({ni, nj});
                    }
                }
            }
            ++ans;
        }
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(dist[i][j] == -1 && grid[i][j] == 1) return -1;
            }
        }
        if(sz == 0) return 0;
        return ans - 1;
    }
};