class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, mul = 1, r = 0;
        for(int i = 0;i < n;++i){
            mul *= nums[i];
            while(r < i && mul >= k){
                mul /= nums[r++];
            }
            if(mul < k)
            ans += (i - r + 1);
        }
        return ans ;
    }
};