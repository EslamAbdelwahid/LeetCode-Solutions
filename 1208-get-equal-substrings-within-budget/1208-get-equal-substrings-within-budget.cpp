class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), sum = 0, ans = 0;
        int l = 0;
        for(int i = 0;i < n;++i){
            sum += abs(s[i] - t[i]);
            while(sum > maxCost && l <= i){
                sum -= abs(s[l] - t[l]);
                ++l;
            }
            ans = max(ans, i - l + 1);
        }
        return ans ;
    }
};