class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> fre1, fre2;
        for(auto &i : nums1){
            if(!fre1[i]) fre1[i]++;
        }
        for(auto &i : nums2){
            if(!fre2[i]) fre2[i]++;
        }
        int ans = 2e9;
        for(auto &[l, r] : fre1){
            if(fre2[l]) ans = min(ans, l);
        }
        if(ans == 2e9) ans = -1;
        return ans;
    }
};