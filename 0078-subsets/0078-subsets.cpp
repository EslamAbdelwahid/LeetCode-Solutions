class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0;i < (1ll << n);++i){
            vector<int>v ;
            for(int j = 0;j < n;++j){
                if((i >> j) & 1) v.push_back(nums[j]);
            }
            ans.push_back(v);
        }
        return ans ;
    }
};