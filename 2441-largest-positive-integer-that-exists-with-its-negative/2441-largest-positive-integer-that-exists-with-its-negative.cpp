class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map < int, int > fre;
        for(auto &i : nums) fre[i]++;
        int ans = -100000;
        for(auto &i : nums){
            if(fre[i] && fre[-i]){
                ans = max(ans, abs(i));
            }
        }
        if(ans == -100000) ans = -1;
        return ans ;
    }
};