class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> fre(26);
        for(auto &i : letters) fre[i-'a']++;
        function<int(int,vector<int>)> best = [&](int i,vector<int>fre2){
            if(i == words.size()) return 0;
            int ret = 0;
            int leave = best(i + 1, fre2), take = 0;
            vector<int> fre3 = fre2;
            bool can = 1;
            int cost = 0;
            for(auto &j : words[i]){
                if(!fre3[j-'a']){
                    can = 0;
                    break;
                }
                cost += score[j - 'a'];
                fre3[j-'a']--;
            }
            if(can) take = best(i + 1, fre3) + cost;
            return max(take, leave);
        };
        return best(0, fre);
    }
};