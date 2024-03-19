class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>fre(26);
        for(auto &i : tasks){
            fre[i-'A']++;
        }
        set < pair<int,int>, greater<pair<int,int>> > st;
        for(int i = 0;i < 26;++i){
            if(fre[i]) st.insert({fre[i], i});
        }
        vector<int>last(26,0);
        int i = 1;
        while(st.size()){
            bool ok = 0;
            pair<int,int> Max = {-1,-1};
            for(auto &[l, r] : st){
                if(!last[r]||(i - last[r] - 1 >= n)){
                    if(l - 1){
                        st.insert({l-1, r});
                    }
                    last[r] = i;
                    st.erase({l, r});
                    ok = 1;
                    break;
                }else{
                    Max = max(Max, {l, r});
                }
            }
            if(!ok){
                if(Max.first != - 1){
                    int found = i - last[Max.second] - 1;
                    int need = n - found ;
                    i += need;
                    if(Max.first - 1) st.insert({Max.first-1, Max.second});
                    last[Max.second] = i;
                    st.erase(Max);
                }
            }
            ++i;
        }
        return i-1;
    }
};