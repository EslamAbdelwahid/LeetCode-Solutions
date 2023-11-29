class Solution {
public:
int dx[8] = {0,  0, 1, -1,  1, -1, 1, -1};
int dy[8] = {1, -1, 0,  0, -1,  1, 1, -1};
int dist[105][105] , vis[105][105];
    int minCost(vector<vector<int>>& grid) {
        priority_queue<array<int,3>,vector<array<int,3>> , greater<array<int,3>>>q;
        for(int i = 0;i <= 101;++i){
            for(int j =0 ;j <= 101;++j){
                dist[i][j] = 1e9;
                vis[i][j] = 0;
            }
        }
        int n = grid.size();
        int m = grid[0].size();
        q.push({0,0,0});
        dist[0][0] = 0;
        while(q.size()){
            auto node = q.top(); q.pop();
            int cost = node[0] , i = node[1] , j = node[2];
            int indx = grid[i][j] - 1;
            for(int k = 0;k < 4;++k){
                int ni = i + dx[k] , nj = j + dy[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && cost + (indx != k) < dist[ni][nj]){
                    dist[ni][nj] = cost + (indx != k);
                    q.push({dist[ni][nj] , ni , nj});
                }
            }

        }
        return dist[n-1][m - 1];
    }
};