
class trie{
    private :
    static const int Max = 26;
    trie* child[Max];
    bool isLeaf {};
    public : 
    trie(){
        isLeaf = false;
        memset(child, 0, sizeof(child));
    }
    void insert(string word){
        trie* cur = this;
        for(auto &i : word){
            int ch = i - 'a';
            if(cur->child[ch] == 0) cur->child[ch] = new trie();
            cur = cur->child[ch];
        }
        cur->isLeaf = true;
    }
    string replace(string word){
        trie *cur = this;
        string ans = "";
        for(auto &i : word){
            int ch = i - 'a';
            if(cur->child[ch] == 0) return word;
            ans += i;
            cur = cur->child[ch];
            if(cur->isLeaf) return ans;
        }
        if(cur->isLeaf) return ans;
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie root;
        for(auto &word : dictionary){
            root.insert(word);
        }
        string word = "", ans = "";
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
        return ans;
    }
};