class Solution {
public:
    long long dp[500005][2][4];
    const long long mod = 1e9 + 7;
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return calc(0 ,0 ,0, n) % mod;
    }
    long long calc(int i, bool absent, int late,int n){
        if(i == n) return 1;
        long long &ret = dp[i][absent][late];
        if(~ret) return ret ;
        ret = 0;
        if(!absent) ret += calc(i + 1, 1, 0, n) % mod, ret %= mod;
        ret += calc(i + 1, absent, 0, n) % mod, ret %= mod;
        if(late + 1 < 3)
        ret += calc(i + 1, absent, late + 1, n) % mod, ret %= mod;
        return ret;
    }
    
};