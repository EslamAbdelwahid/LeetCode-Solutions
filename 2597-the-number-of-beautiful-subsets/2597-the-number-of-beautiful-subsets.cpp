class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        function<int(int,int)> calc = [&](int i, int Mask){
            bitset < 20 > mask = Mask;
            if(i == nums.size()) return 1;
            int ret = calc(i + 1, Mask);
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