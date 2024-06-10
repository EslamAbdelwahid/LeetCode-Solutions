class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        unordered_map < int, int > fre;
        for(auto &i : heights) fre[i]++ ;
        int st = 1, ans = 0;
        for(auto &i : heights){
            while(!fre[st]) ++st;
            ans += (st != i);
            --fre[st];
        }
        return ans ;
    }
};