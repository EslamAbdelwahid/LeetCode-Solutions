class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.size();
        vector<int>fre(26);
        for(auto &i : s) fre[i - 'a']++;
        string ans = "";
        for(auto &i : order){
           int &x = fre[i - 'a'];
            while(x){
                ans += i, --x;
            }
        }
        for(auto &i : s){
            int &x = fre[i - 'a'];
            while(x){
                ans += i, --x;
            }
        }
        
        return ans;
    }
};