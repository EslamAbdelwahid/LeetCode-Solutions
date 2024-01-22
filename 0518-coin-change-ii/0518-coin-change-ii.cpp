class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size() + 5, vector<int>(amount + 5, -1));
        return count(0, amount, coins, dp);
    }
    int count(int i, int rem, vector<int>&coins, vector<vector<int>>&dp){
        if(i == coins.size()) return rem == 0;
        int &ret = dp[i][rem];
        if(~ret) return ret;
        ret = count(i + 1, rem , coins, dp);
        if(rem - coins[i] >= 0){
            ret += count(i, rem - coins[i], coins, dp);
        }
        return ret;
    }
};