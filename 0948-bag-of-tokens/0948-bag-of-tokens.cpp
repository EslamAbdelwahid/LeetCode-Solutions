class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0, ans = 0;
        int l = 0, n = tokens.size(), r = n - 1;
        while(l <= r){
            if(power - tokens[l] >= 0){
                ++score;
                power -= tokens[l];
                ++l;
                ans = max(ans, score);
            }else if(score){
                --score;
                power += tokens[r--];
            }else return ans;
        }
        return ans;
    }
};