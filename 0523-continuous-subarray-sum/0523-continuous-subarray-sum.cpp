class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen ;
        int n = nums.size();
        int prefix_mod = 0;
        seen[0] = -1;
        for(int i = 0;i < n;++i){
            nums[i] %= k;
            prefix_mod = (prefix_mod + nums[i]) % k;
            if(seen.find(prefix_mod) != seen.end()){
                if(i - seen[prefix_mod] > 1) return true; 
            }else{
                seen[prefix_mod] = i;
            }
        }
        return false;
    }
};