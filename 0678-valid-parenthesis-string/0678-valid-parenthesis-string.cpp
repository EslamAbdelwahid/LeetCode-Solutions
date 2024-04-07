class Solution {
public:
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(), -1));
        return solve(0, 0, s, dp);
    }
    bool solve(int i, int open,const string &s, vector<vector<int>>&dp){
        if(i == s.size()) return open  == 0;
        int &ret = dp[i][open];
        if(~ret) return ret;
        ret = 0;
        if(s[i] == '('||s[i] == '*') ret |= solve(i + 1, open + 1, s, dp);
        if( (s[i] == ')' || s[i] =='*') && open) ret |= solve(i + 1, open - 1, s, dp);
        if(s[i] == '*') ret |= solve(i + 1, open, s, dp);
        return ret;
    }
};