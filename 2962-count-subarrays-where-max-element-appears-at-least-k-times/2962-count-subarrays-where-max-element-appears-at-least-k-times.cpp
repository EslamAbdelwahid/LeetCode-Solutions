class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int Max = *max_element(nums.begin(), nums.end());
        int fre = 0, l = 0, r = 0;
        long long ans = 0;
        while(l < n){
            while(r < n && fre < k){
                if(nums[r] == Max) ++fre;
                ++r;
            }
            if(fre == k) ans += n - r + 1;
            if(nums[l] == Max) --fre;
            ++l;
        }
        return ans; 
    }
};