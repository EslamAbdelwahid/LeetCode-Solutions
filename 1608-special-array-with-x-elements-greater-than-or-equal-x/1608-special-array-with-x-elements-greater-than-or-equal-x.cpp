class Solution {
public:
    int specialArray(vector<int>& nums) {
        for(int x =1;x <= nums.size();++x){
            int cnt = 0;
            for(int i = 0;i < nums.size();++i){
                if(nums[i] >= x) ++cnt;
            }
            if(cnt == x) return x;
        }
        return -1;
    }
};