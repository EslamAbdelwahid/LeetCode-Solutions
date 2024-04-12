class Solution {
public:
    string removeKdigits(string num, int k) {
        stack < char > st;
        for(auto &i : num){
            if(st.empty()) st.push(i);
            else{
                while(st.size() && i < st.top() && k){
                    st.pop(), --k;
                }
                st.push(i);
            }
        }
        while(st.size() && k) st.pop(), --k;
        string ans ;
        while(st.size()) ans += st.top(), st.pop();
        while(ans.size() && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        if(ans.size() == 0) return "0";
        return ans ;
    }
};