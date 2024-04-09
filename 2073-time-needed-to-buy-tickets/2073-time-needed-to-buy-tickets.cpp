class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int,int>> q;
        for(int i = 0;i < n;++i) q.push({tickets[i], i});
        int ans = 0;
        while(true){
            int val = q.front().first, idx = q.front().second;
            q.pop();
            if(val == 1 && idx == k){ 
                ++ans;break;
            }
            if(val) q.push({val - 1, idx}), ++ans;
        }
        return ans ;
    }
};