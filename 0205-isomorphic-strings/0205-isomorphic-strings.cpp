class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int> idxs, idxt;
        for(int i = 0;i < s.size();++i){
            if(idxs[s[i]-'a'] != idxt[t[i]-'a']) return false;
            idxs[s[i]-'a'] = i + 1;
            idxt[t[i]-'a'] = i + 1;
        }
        return true;
    }
};