class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(1 << nums.size(), -1));
        function<int(int,int)> calc = [&](int i, int Mask){
            bitset < 20 > mask = Mask;
            if(i == nums.size()) return 1;
            int &ret = dp[i][Mask];
            if(~ret) return ret;
            ret = calc(i + 1, Mask);
            for(int j = 0;j < i;++j){
                if(mask[j] && abs(nums[i] - nums[j]) == k){
                    return ret ;
                }
            }
            mask[i] = 1;
            ret += calc(i + 1, mask.to_ulong());
            mask[i] = 0;
            return ret ;
        };
        
        return calc(0, 0) - 1;
    }
    
};