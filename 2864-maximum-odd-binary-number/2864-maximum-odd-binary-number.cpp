class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0;
        for(auto &i : s) cnt += (i == '1');
        s[s.size() - 1] = '1';
        --cnt;
        int i = 0;
        while(cnt && i < s.size()-1){
            s[i++] = '1', --cnt;
        }
        while(i < s.size() - 1) s[i++] = '0';
        return s;
    }
};