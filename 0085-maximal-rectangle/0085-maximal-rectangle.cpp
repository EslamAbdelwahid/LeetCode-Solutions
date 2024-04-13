class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans  = 0;
        vector<int>heights(m);
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            
        int k = heights.size();
        vector<int>leftsmaller(k), rightsmaller(k);
        stack < int > st;
        for(int x = k - 1;x >= 0;--x){
            int idx = k;
            while(st.size() && heights[st.top()] >= heights[x]){
                st.pop();
            }
            if(st.size() && heights[st.top()] < heights[x]) idx = st.top();
            rightsmaller[x] = idx;
            st.push(x);
        }
        while(st.size()) st.pop();
        for(int x = 0;x < k;++x){
            int idx = -1;
            while(st.size() && heights[st.top()] >= heights[x]){
                st.pop();
            }
            if(st.size() && heights[st.top()] < heights[x]) idx = st.top();
            leftsmaller[x] = idx;
            st.push(x);
        }
            while(st.size()) st.pop();
            for(int x = 0;x < k;++x){
            ans = max(ans, heights[x] * (x - leftsmaller[x] + rightsmaller[x] - x - 1));
        }
        }
        return ans ;
    }
   
};