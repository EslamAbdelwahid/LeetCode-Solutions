class Solution {
public:
    bool isValid(string s) {
        stack < char > st;
        for(int i = 0;i < s.size();++i){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else {
                if(st.empty()) return false;
                char lst = st.top(); st.pop();
                if(s[i] != get(lst)) return false;
            }
        }
        return st.size() == 0;
    }
    char get(char c){
        if(c == '(') return ')';
        if(c == '[') return ']';
        return '}';
    }
};