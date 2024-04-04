class Solution {
public:
    int maxDepth(string s) {
        int L = 0, R = 0, ans = 0;
        for(int i = 0;i < s.size();++i){
            if(s[i] == '(') ++L, ans = max(ans, L);
            else if(s[i] == ')'){
                --L;
            }else if(s[i + 1] == ')'){
                ans = max(ans, L);
            }
        }
        return ans ;
    }
};