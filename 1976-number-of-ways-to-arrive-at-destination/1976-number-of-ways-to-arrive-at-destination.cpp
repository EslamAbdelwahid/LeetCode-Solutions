class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    vector<long long> Ways(205,0),dist(205,1e18);
    q.push({0,0});
    dist[0] = 0;
    Ways[0] = 1;
    long long mod = 1e9 + 7;
    vector <pair<long long,int>>graph[205];
    for(auto &i : roads){
        long long u = i[0],v = i[1] , cost = i[2];
        graph[u].push_back({v , cost});
        graph[v].push_back({u , cost});
    }
    while (q.size()){
        auto node = q.top(); q.pop();
        long long u = node.second , cost = node.first;
        for(auto &[v , w] : graph[u]){
           if(w + cost < dist[v]){
               dist[v] = w + cost;
               Ways[v] = Ways[u];
               q.push({dist[v] , v});
           }else if(w + cost == dist[v]){
               Ways[v] = (Ways[v] + Ways[u]) % mod;
           }
        }
    }
    return Ways[n-1];
    }
};