class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l <= r){
            if(l == r) return 1;
            if(s[r] != s[l]){
                return r - l + 1;
            }
            while(l <= r && s[l] == s[r]) ++l;
            char c = s[r];
            while(r >= l && s[r] == c) --r;
        }
        return 0;
    }
};