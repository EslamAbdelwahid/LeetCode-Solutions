class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map < string, bool > found ;
        for(auto &i : wordDict) found[i] = true;
        vector<string> ans ;
        function<void(int, string)> rec = [&](int i, string t){
            if(i == s.size()){
                ans.push_back(t);
                return ;
            }
            string construct;
            for(int j = i;j < s.size();++j){
                construct += s[j];
                if(found[construct]){
                    string temp = t;
                    t += construct;
                    if(j + 1 < s.size()) t += ' ';
                    rec(j + 1, t);
                    t = temp;
                }
            }
        };
        string t;
        rec(0, t);
        return ans ;
    }
};