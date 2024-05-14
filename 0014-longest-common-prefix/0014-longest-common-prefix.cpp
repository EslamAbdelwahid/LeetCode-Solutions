string ans ;
class Trie{
private : 
    Trie* child[26];
    bool is;
    int cnt;
public : 
    Trie(){
        memset(child, 0, sizeof(child));
        is = false;
        cnt = 0;
    }
    void add(string &s){
        Trie* cur = this;
        for(auto &ch : s){
            int x = ch - 'a';
            if(!cur->child[x]) cur->child[x] = new Trie();
            cur = cur->child[x];
            cur->cnt++;
        }
        is = true;
    }
    void longest_common_prefix(int siz){
        for(int i = 0;i < 26;++i){
            if(child[i] && child[i]->cnt == siz){
                char c = 'a';
                c += i;
                ans += c;
                child[i]->longest_common_prefix(siz);
            }
        }
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(auto &i : strs){
            trie.add(i);
        }
        ans = "";
        trie.longest_common_prefix(strs.size());
        return ans ;
    }
};