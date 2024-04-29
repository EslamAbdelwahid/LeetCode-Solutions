class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0 , n = nums.size();
        for(int i = 0;i < 27;++i){
            int k_bit = ((k >> i) & 1);
            int Xor = 0;
            for(auto &j : nums){
                Xor ^= ((j >> i) & 1);
            }
            ans += (Xor != k_bit);
        }
        return ans ;
    }
};