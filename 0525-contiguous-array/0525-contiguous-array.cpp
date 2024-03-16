class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> First_indx;
        First_indx[0] = -1;
        int sum = 0, ans = 0;
        for(int i = 0;i < nums.size();++i){
            sum += (nums[i] == 1 ? 1 : -1);
            if(First_indx.count(sum)){
                ans = max(ans, i - First_indx[sum]);
            }else{
                First_indx[sum] = i;
            }
        }
        return ans;
    }
   
};