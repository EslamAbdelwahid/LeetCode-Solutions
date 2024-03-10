class Trie{
private:
    Trie* child[26];
    bool is_leaf = false;
    vector<int>index;
public:
    Trie(){
        memset(child,0, sizeof(child));
    }
    void insert(string word, int indx){
        Trie* cur = this;
        for(auto &i : word){
            int ch = i - 'a';
            if(!cur->child[ch])
                cur->child[ch] = new Trie();
            cur->child[ch]->index.push_back(indx);
            cur = cur->child[ch];
        }
        cur->is_leaf = true;
    }
    vector<int> get_indices(string &prefix){
        Trie* cur = this;
        for(auto &i : prefix){
            int ch = i - 'a';
            if(!cur->child[ch]) return {};
            cur = cur->child[ch];
        }
        return cur->index;
    }
};

class WordFilter {
private:
    Trie tree;
    vector<string> all_words;
public:
    WordFilter(vector<string>& words) {
        map < string, bool > fre;
        for(int i = words.size() - 1;i >= 0;--i){
            if(!fre[words[i]]){
                tree.insert(words[i], i);
            }
            fre[words[i]] = true;
        }
        all_words = words;
    }

    int f(string pref, string suff) {
        vector<int>indices = tree.get_indices(pref);
        sort(indices.begin(), indices.end(), greater<int>());
        for(auto &i : indices){
            string word = all_words[i];
            if(suffix_exist(word , suff)) {
                return i;
            }
        }
        return -1;
    }
    bool suffix_exist(const string& word, const string &suff){
        int i = word.size() - 1, j = suff.size() - 1;
        if(suff.size() > word.size()) return false;
        while(i >= 0 && j >= 0 && suff[j] == word[i]){
            --i,--j;
        }
        return j < 0;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */