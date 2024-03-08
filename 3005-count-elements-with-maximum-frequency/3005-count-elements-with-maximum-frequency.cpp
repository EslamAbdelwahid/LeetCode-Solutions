class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>fre;
        int mx = 0;
        for(auto &i : nums) fre[i]++,mx = max(mx, fre[i]);
        int ans = 0;
        for(auto &[l, r] : fre){
            ans += (r == mx ? r : 0);
        }
        return ans;
    }
};