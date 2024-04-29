class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>>adj(n);
        vector<int> indegree(n);
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            indegree[i[1]]++;
        }
        queue<int> q;
        for(int i = 0;i < n;++i){
            if(indegree[i] == 1) q.push(i);
        }
        while(n > 2){
            int sz = q.size();
            while(sz--){
            int u = q.front();
                --n;
            q.pop();
            for(auto &v : adj[u]){
                indegree[v]--;
                 if(indegree[v] == 1) q.push(v);
              }
           }
        }
        vector<int> ans;
        while(q.size()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans ;
    }
    
};