class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>leftsmaller(n), rightsmaller(n);
        stack < int > st;
        for(int i = n - 1;i >= 0;--i){
            int idx = n;
            while(st.size() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.size() && heights[st.top()] < heights[i]) idx = st.top();
            rightsmaller[i] = idx;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i = 0;i < n;++i){
            int idx = -1;
            while(st.size() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.size() && heights[st.top()] < heights[i]) idx = st.top();
            leftsmaller[i] = idx;
            st.push(i);
        }
        
        int ans = 0;
        for(int i = 0;i < n;++i){
            ans = max(ans, heights[i] * (i - leftsmaller[i]));
            ans = max(ans, heights[i] * (rightsmaller[i] - i));
            ans = max(ans, heights[i] * (i - leftsmaller[i] + rightsmaller[i] - i - 1));
        }
        return ans ;
    }
};