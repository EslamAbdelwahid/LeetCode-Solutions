class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        unordered_map<int,int>hashMap; 
        for(int i = 0;i < n;++i){
            hashMap[nums[i]] = i;
        }
        vector<vector<int>>ans;
        for(int i = 0;i < n - 2;++i){
            if(nums[i] > 0) break;
            for(int j = i + 1;j < n - 1;++j){
                int numsk = -nums[i] - nums[j];
                if(hashMap.count(numsk) && hashMap.find(numsk)->second > j){
                    ans.push_back({nums[i], nums[j], numsk});
                    j = hashMap.find(nums[j])->second;
                }
            }
           i = hashMap[nums[i]];
        }
        return ans;
    }
};
