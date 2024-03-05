class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map < char, int > fre;
        int ans = 0, l = 0, r = 0;
        while(l < n){
            while(r < n && (fre[s[r]] + 1) <= 1){
                fre[s[r++]]++;
            }
            ans = max(ans, r - l);
            fre[s[l++]]--;
        }
        return ans;
    }
};