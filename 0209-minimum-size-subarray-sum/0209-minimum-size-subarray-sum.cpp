class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = 0, ans = 1e9, sum = 0;
        while(l <= r){
            while(r < n && sum < target){
                sum += nums[r++];
            }
            if(sum >= target){
                ans = min(ans, r - l);
            }
            if(l < n)
            sum -= nums[l];
            ++l;
        }
        if(ans == 1e9) ans = 0;
        return ans;
    }
};