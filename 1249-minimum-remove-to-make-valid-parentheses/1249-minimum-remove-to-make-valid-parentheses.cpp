class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int>remove(s.size());
        stack < int > st;
        for(int i = 0;i < s.size();++i){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                if(st.size()) st.pop();
                else remove[i] = 1;
            }
        }
        while(st.size()) remove[st.top()] = 1, st.pop();
        string ans;
        for(int i = 0;i < s.size();++i){
            if(!remove[i]) ans += s[i];
        }
        return ans ;
    }
};