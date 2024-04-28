class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>>dp(key.size(), vector<int>(ring.size(), -1));
        vector<vector<int>>adj(26);
        for(int i = 0;i < ring.size();++i){
            adj[ring[i] - 'a'].push_back(i);
        }
        return best(0, 0, ring, key, dp, adj);
    }
    int best(int i, int lst,string &ring, string &key, vector<vector<int>>&dp,vector<vector<int>>&adj){
        if(i == key.size()) return key.size();
        int &ret = dp[i][lst];
        if(~ret) return ret ;
        ret = 1e9;
        for(auto &j : adj[key[i] - 'a']){
            if(ring[j] == key[i]){
                int add = abs(lst - j);
                if(j < lst){
                    add = min(add, (int)ring.size() - lst + j);
                }
                add = min(add, (int)ring.size() - j + lst);
                ret = min(ret, best(i + 1, j, ring, key, dp, adj) + add);
            }
        }
        return ret ;
    }
};