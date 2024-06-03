class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, n = s.size(), m = t.size();
        int ans = 0;
        for(int j = 0;j < m;++j){
            while(i < n && s[i] != t[j]){
                ++i;
            }
            if(i == n) return m - j;
            ++i;
        }
        return 0;
    }
};