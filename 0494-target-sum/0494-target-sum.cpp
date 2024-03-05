class Solution {
    map < pair<int,int>, int > dp;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, nums, target);
    }
    int solve(int i, vector<int>&nums, int tar){
        if(i == nums.size()) return tar == 0;
        if(dp.find({i, tar}) != dp.end()) return dp[{i, tar}];
        int ret = 0;
        ret += solve(i + 1, nums, tar - nums[i]);
        ret += solve(i + 1, nums, tar + nums[i]);
        return  dp[{i, tar}] = ret;
    }
};