class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0;i < (1ll << n);++i){
            int sum = 0;
            for(int j = 0;j < n;++j){
                if((i >> j) & 1){
                    sum ^= nums[j];
                }
            }
            ans += sum;
        }
        return ans ;
    }
};