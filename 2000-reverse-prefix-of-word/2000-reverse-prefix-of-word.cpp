class Solution {
public:
    string reversePrefix(string word, char ch) {
        int l = 0, r = 0;
        for(int i = 0;i < word.size();++i){
            if(word[i] == ch){
                r = i;break;
            }
        }
        while(l < r) swap(word[l++],word[r--]);
        return word ;
    }
};