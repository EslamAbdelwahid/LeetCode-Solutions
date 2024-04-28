class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>>dp(key.size(), vector<int>(ring.size(), -1));
        return best(0, 0, ring, key, dp);
    }
    int best(int i, int lst,string &ring, string &key, vector<vector<int>>&dp){
        if(i == key.size()) return key.size();
        int &ret = dp[i][lst];
        if(~ret) return ret ;
        ret = 1e9;
        for(int j = 0;j < ring.size();++j){
            if(ring[j] == key[i]){
                int add = abs(lst - j);
                if(j < lst){
                    add = min(add, (int)ring.size() - lst + j);
                }
                add = min(add, (int)ring.size() - j + lst);
                ret = min(ret, best(i + 1, j, ring, key, dp) + add);
            }
        }
        return ret ;
    }
};