class Trie{
private:
    Trie* child[26];
    bool is_leaf;
public:
    Trie(){
        memset(child, 0, sizeof(child));
        is_leaf = false;
    }
    void add(string &word){
        Trie* cur = this;
        for(auto &ch : word){
            int idx = ch - 'a';
            if(!cur->child[idx]) cur->child[idx] = new Trie();
            cur = cur->child[idx];
        }
        cur->is_leaf = true;
    }
    string replace(string &word){
        string ans ;
        Trie *cur = this;
        for(auto &ch : word){
            int idx = ch - 'a';
            if(cur->is_leaf) return ans;
            if(cur->child[idx]) cur = cur->child[idx];
            else break;
            ans += ch;
        }
        if(cur->is_leaf) return ans;
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie root = Trie();
        for(auto &i : dictionary) root.add(i);
        string word, ans ;
        for(auto &i : sentence){
            if(i == ' '){
                ans += root.replace(word);
                ans += " ";
                word = "";
            }else{
                word += i;
            }
        }
        ans += root.replace(word);
        return ans ;
    }
};