class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>idxs(200),idxt(200);
        for(int i = 0;i < s.size();++i){
            if(idxs[s[i]] != idxt[t[i]]) return false;
            idxs[s[i]] = i + 1;
            idxt[t[i]] = i + 1;
        }
        return true;
    }
};