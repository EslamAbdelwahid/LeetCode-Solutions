class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, ans = 0;
        unordered_map < int, int > fre;
        while(l < n){
            while(r < n && fre[nums[r]] + 1 <= k){
                fre[nums[r++]]++;
            }
            ans = max(ans, r - l);
            fre[nums[l++]]--;
        }
        return ans;
    }
};