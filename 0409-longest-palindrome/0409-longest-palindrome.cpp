class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <char,int>fre;
        for(auto &i : s){
            fre[i]++;
        }
        int ans = 0;
        bool is = 0;
        for(auto &[l, r] : fre){
            if(r & 1) ans += r - 1, is = 1;
            else ans += r;
        }
        return ans + is ;
    }
};