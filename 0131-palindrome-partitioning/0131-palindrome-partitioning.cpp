class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        unordered_map<string,bool> is_pal;
        function<bool(string)> check=[&](string x){
            string y = x;
            reverse(y.begin(), y.end());
            return x == y;
        };
        for(int i = 1;i <= n;++i){
            for(int j = 0;j + i <= n;++j){
                string t = s.substr(j, i);
                is_pal[t] = check(t);
            }
        }
        vector<vector<string>> ans;
        
        function<void(int, vector<string>)> dfs = [&](int i, vector<string>part){
            if(i == s.size()){
                ans.push_back(part);
                return ;
            }
            string t;
            for(int j = i;j < s.size();++j){
                t += s[j];
                if(is_pal[t]){
                    part.push_back(t);
                    dfs(j + 1, part);
                    part.pop_back();
                }
            }
        };
        vector<string> part;
        dfs(0, part);
        return ans;
    }
};