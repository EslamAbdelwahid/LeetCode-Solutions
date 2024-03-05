class Solution {
public:
    string minWindow(string s, string t) {
        map < char, int > fre;
        for(auto &i : t) fre[i]++;
        int l = 1, r = s.size();
        pair<int,int> ans = {-1,-1};
        while(l <= r){
            int mid = (l + r) / 2;
            auto sub = can(mid, fre, s);
            if(sub.first != -1){
                ans = sub;
                r = mid - 1;
            }else l = mid + 1;
        }
        if(ans.first == -1) return "";
        return s.substr(ans.first, ans.second - ans.first + 1);
    }
    pair<int,int> can(int mid, map<char,int>&fre_t, string &s){
        map < char, int > fre_s;
        for(int i = 0;i < mid;++i){
            fre_s[s[i]]++;
        }
        if(valid(fre_s, fre_t)) return {0, mid - 1};
        for(int i = mid;i < s.size();++i){
            fre_s[s[i]]++;
            fre_s[s[i - mid]]--;
            if(valid(fre_s, fre_t)) return {i - mid + 1, i};
        }
        return {-1,-1};
    }
    bool valid(map<char,int>&fre_s,map<char,int>&fre_t){
        for(auto &[l, r] : fre_t){
            if(fre_s[l] < r) return 0;
        }
        return 1;
    }
};