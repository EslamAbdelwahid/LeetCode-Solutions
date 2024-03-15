class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n,1), suffix(n,1), ans;
        prefix[0] = nums[0];
        for(int i = 1;i < n;++i){
            prefix[i] = prefix[i - 1] * nums[i];
        }
        suffix[n-1] = nums[n-1];
        for(int i = n - 2;i >=0 ;--i){
            suffix[i] = suffix[i + 1] * nums[i];
        }
        for(int i = 0;i < n;++i){
            int x = 1, y = 1;
            if(i - 1 >= 0) x = prefix[i - 1];
            if(i + 1 < n) y = suffix[i + 1];
            ans.push_back(x * y);
        }
        return ans;
    }
};