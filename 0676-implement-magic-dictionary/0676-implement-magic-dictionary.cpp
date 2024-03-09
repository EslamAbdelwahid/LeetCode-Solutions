class Trie{
private:
    Trie* child[26];
    bool is_leaf = false;
public:
    Trie(){
        memset(child,0, sizeof(child));
    }
    void insert(string word){
        Trie* cur = this;
        for(auto &i : word){
            int ch = i - 'a';
            if(!cur->child[ch])
                cur->child[ch] = new Trie();
            cur = cur->child[ch];
        }
       cur->is_leaf = true;
    }
    bool word_exist( string word){
        Trie* cur = this;
        for(auto &i : word){
            int ch = i - 'a';
            if(!cur->child[ch])
               return false;
            cur = cur->child[ch];
        }
        return cur->is_leaf;
    }
};

class MagicDictionary {
private:
    Trie tree;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &word : dictionary){
            tree.insert(word);
        }
    }
    
    bool search(string searchWord) {
        for(int i = 0;i < searchWord.size();++i){
            for(int j = 0;j < 26;++j){
                if(j != searchWord[i] - 'a'){
                    char lst = searchWord[i];
                    searchWord[i] = char(j + 'a');
                    if(tree.word_exist(searchWord)) return true;
                    searchWord[i] = lst;
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */