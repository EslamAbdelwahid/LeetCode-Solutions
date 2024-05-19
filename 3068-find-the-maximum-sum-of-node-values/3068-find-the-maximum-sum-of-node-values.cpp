class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1));
        return best(0, 0, k, nums, dp);
    }
    long long best(int i, int parity, int k, vector<int>& arr, vector<vector<long long>>&dp){
        if(i == arr.size()){
            if(parity == 0) return 0;
            return -1e18;
        }
        long long &ret = dp[i][parity];
        if(~ret) return ret;
        ret = best(i + 1, parity, k, arr, dp) + arr[i];
        ret = max(ret, best(i + 1, parity ^ 1, k, arr, dp) + (arr[i] ^ k));
        return ret;
    }
};