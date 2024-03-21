class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return DP(0, nums, dp);
    }
    int DP(int i, vector<int>&nums, vector<int>&dp){
        if(i == nums.size() - 1) return 0;
        int &ret = dp[i];
        if(~ret) return ret;
        ret = 1e9;
        for(int j = 1;j <= nums[i];++j){
            if(i + j < nums.size()) ret = min(ret, DP(i + j, nums, dp) + 1);
        }
        return ret;
    }
};