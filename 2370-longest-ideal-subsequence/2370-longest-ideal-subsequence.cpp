class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<vector<int>>dp(s.size(), vector<int>(27,-1));
        return best(0, 26, k, s, dp);
    }
    int best(int i, int lst, int &k, string &s, vector<vector<int>>&dp){
        if(i == s.size()) return 0;
        int &ret = dp[i][lst];
        if(~ret) return ret ;
        ret = best(i + 1, lst, k, s, dp);
        if(lst == 26 || abs(s[i] - 'a' - lst) <= k ) ret = max(ret, best(i + 1, s[i] - 'a', k, s, dp) + 1);
        return ret; 
    }
};