class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n, 1e9);
        dist[k - 1] = 0;
        for(int i = 0;i < n - 1;++i){
            for(auto &edge : times){
                int u = edge[0]-1, v = edge[1]-1, cost = edge[2];
                if(dist[v] > dist[u] + cost){
                    dist[v] = dist[u] + cost;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < n;++i){
            if(dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};