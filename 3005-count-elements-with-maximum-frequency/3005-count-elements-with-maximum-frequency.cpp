class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>fre(101);
        int mx = 0;
        for(auto &i : nums) fre[i]++,mx = max(mx, fre[i]);
        int ans = 0;
        for(int i = 1;i < 101;++i){
            if(fre[i] == mx) ans += mx;
        }
        return ans;
    }
};