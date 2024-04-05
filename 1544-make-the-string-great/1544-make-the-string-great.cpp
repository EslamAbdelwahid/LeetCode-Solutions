class Solution {
public:
    string makeGood(string s) {
        string ans;
        for(auto &i : s){
            if(ans.size()==0) ans += i;
            else {
                if(ans.back() != i && tolower(ans.back()) == tolower(i)){
                    ans.pop_back();
                }else ans += i;
            }
        }
        return ans;
    }
};