class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>adjMatrix(n,vector<int>(n,1e9));
        for(auto &i : times){
            int u = i[0] - 1, v = i[1] - 1, w = i[2];
            adjMatrix[u][v] = min(adjMatrix[u][v], w);
        }
        for(int i = 0;i < n;++i) adjMatrix[i][i] = 0;
        for(int k = 0;k < n;++k){
            for(int i = 0;i < n;++i){
                for(int j = 0;j < n;++j){
                    if(adjMatrix[i][k] == 1e9 || adjMatrix[k][j] == 1e9) continue;
                    int relax = adjMatrix[i][k] + adjMatrix[k][j];
                    adjMatrix[i][j] = min(adjMatrix[i][j], relax);
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < n;++i){
            if(adjMatrix[k - 1][i] == 1e9) return -1;
            ans = max(ans, adjMatrix[k - 1][i]);
        }
        return ans;
    }
};