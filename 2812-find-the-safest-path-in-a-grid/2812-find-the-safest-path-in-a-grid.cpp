class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] || grid[n-1][m-1]) return 0;
        queue<pair<int,int>> q;
        vector<vector<int>>dist(n,vector<int>(m,-1));
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(grid[i][j]){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto [i, j] = q.front(); q.pop();
                for(int k = 0;k < 4;++k){
                    int ni = i + dx[k], nj = j + dy[k];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && !grid[ni][nj] && dist[ni][nj] == -1){
                        dist[ni][nj] = dist[i][j] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }
        
        function<bool(int)> bfs = [&](int target){
            queue<pair<int,int>> q;
            if(dist[0][0] < target) return 0;
            q.push({0, 0});
            vector<vector<bool>>vis(n,vector<bool>(m));
            vis[0][0] = 1;
            while(q.size()){
                auto [i, j] = q.front(); q.pop();
                if(i == n - 1 && j == m - 1) return 1;
                for(int k = 0;k < 4;++k){
                    int ni = i + dx[k], nj = j + dy[k];
                    if(ni >= 0 && ni < n && nj >= 0&& nj < m && !grid[ni][nj] && dist[ni][nj] >= target && !vis[ni][nj]){
                        vis[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }
            return 0;
        };
        int l = 0, r = 1000, ans = 0;
        while(l<=r){
            int mid = (l + r) / 2;
            if(bfs(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }

};