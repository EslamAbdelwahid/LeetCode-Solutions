class Solution {
public:
    
    long long wonderfulSubstrings(string word) {
        long long mask = 0, ans  = 0;
        vector<int> fre(1 << 10);
        fre[0] = 1;
        for(auto &ch : word){
            mask ^= (1 << (ch - 'a'));
            ans += fre[mask];
            for(int i = 0;i < 10;++i){
                int lol = mask ^ (1 << i);
                ans += fre[lol];
            }
            fre[mask]++;
        }
        return ans ;
    }
    
};