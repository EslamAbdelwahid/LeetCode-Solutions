class Solution {
public:
    int mod = 1e9 + 7;
    vector<pair<int,long long>>graph[40009];
    long long dp[40009];
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        for(auto &i : edges){
            int u = i[0] , v = i[1] , w = i[2];
            graph[u].push_back({v , w});
            graph[v].push_back({u  ,w});
        }
        vector<long long>dist = dij(n);
        memset(dp , -1 , sizeof (dp));
        return solve(1 , n , dist);
    }

    vector<long long>dij(int n){
        vector<long long>dist(n+2,1e18);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,n});
        dist[n] = 0;
        while(q.size()){
            auto node = q.top();q.pop();
            int u = node.second , w = node.first;
            for(auto &[v , c] : graph[u]){
                if(c + w < dist[v]){
                    dist[v] = c + w;
                    q.push({dist[v]  , v});
                }
            }
        }
        return dist;
    }
    int solve(int u , int n, vector<long long>&dist){
        if(u == n) return 1;
        long long &ret = dp[u];
        if(~ret) return ret;
        ret = 0;
        for(auto &[v , w] : graph[u]){
            if(dist[v] < dist[u]){
                ret += solve(v , n , dist) % mod , ret %= mod;
            }
        }
        return ret;
    }
};