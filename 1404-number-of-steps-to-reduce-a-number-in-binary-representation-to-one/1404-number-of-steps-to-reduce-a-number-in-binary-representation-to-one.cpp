class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), ans = 0;
        while(s.size() > 1){
            n = s.size();
            if(s[n - 1] == '0') s.pop_back();
            else{
                add_one(s);
            }
            ++ans;
        }
        return ans ;
    }
    void add_one(string &s){
        int n = s.size(), i = n - 1;
        for(;i >= 0 && s[i] == '1'; --i){
            s[i] = '0';
        }
        if(i < 0) s = '1' + s;
        else s[i] = '1';
    }
};