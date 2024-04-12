class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), i = 0, j = n - 1;
        while(i < n && height[i] == 0) ++i;
        while(j > i && height[j] == 0) --j;
        stack < int > st; 
        vector<int>nxt(n);
        for(int k = j;k >= i;--k){
            pair<int, int> lol = {-1, -1};
                while(st.size() && height[st.top()] < height[k]){
                    lol = max(lol, {height[st.top()], st.top()});
                    st.pop();
                }
            if(st.empty()) nxt[k] = lol.second ;
            else nxt[k] = st.top();
            st.push(k);
        }
        int ans = 0;
        for(int k = i;k < j;++k){
            int next = nxt[k];
            int now = height[k];
            if(height[k] < height[next]){
                while(k < next) ans += now - height[k++];
                --k;
            }else{
                ++k;
                now = height[next];
                while(k < next) ans += now - height[k++];
                --k;
            }
        }
       // cout << "\n\n";
        return ans ;
        
    }
};