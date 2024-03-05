class Solution {
    int dp[1001][1001][2];
    string ans;
    char midChar = '#';
public:
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));
        best(0, s.size() - 1, 0 , s);
        build(0, s.size() - 1, 0, s);
        string final_ans=ans;
        if(midChar != '#') final_ans += midChar;
        reverse(ans.begin(),ans.end());
        final_ans += ans;
        return final_ans;
    }
    int best(int l, int r, bool ok, string &s){
        if(l >= r) return l == r;
        int &ret = dp[l][r][ok];
        if(~ret) return ret;
        ret = -1e9;
        if(!ok){
            ret = max(ret, best(l + 1, r, ok,s));
            ret = max(ret, best(l, r-1, ok,s));
        }
        if(s[l] == s[r]){
            ret = max(ret, best(l + 1, r - 1, 1,s) + 2);
        }
        return ret;
    }
     void build(int l, int r, bool ok, string &s){
        if(l == r){
            midChar = s[l];
            return;
        }
        if(r < l) return;
        int &ret = dp[l][r][ok];
        if(!ok){
            if(best(l + 1, r, ok, s) == ret){
                build(l + 1, r, ok, s);
                return;
            }
            if(best(l, r - 1, ok, s) == ret){
                build(l, r - 1,ok, s);
                return;
            }
        }
        if(s[l] == s[r] && ((best(l + 1, r - 1, 1, s) + 2) == ret)){
            ans += s[l];
            build(l + 1, r - 1, 1, s);
            return;
        }
    }
  
};