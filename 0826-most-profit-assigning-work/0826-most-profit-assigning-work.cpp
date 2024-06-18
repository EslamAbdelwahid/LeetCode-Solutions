

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size(), m = worker.size();
        vector<array<int,2>> arr(n);
        for(int i = 0;i < n;++i){
            arr[i][0] = difficulty[i];
            arr[i][1] = profit[i];
        }
        sort(arr.begin(), arr.end());
        for(int i = 0;i < n;++i){
            difficulty[i] = arr[i][0];
            profit[i] = arr[i][1];
        }
        vector<int> pref(n+5,0);
        pref[0] = profit[0];
        for(int i = 1;i < n;++i){
            pref[i] = max(pref[i - 1], profit[i]);
        }
        int ans = 0;
        for(int i = 0;i < m;++i){
            auto it = upper_bound(difficulty.begin(), difficulty.end(), worker[i]) - difficulty.begin() - 1;
            if(it>=0)
            ans += pref[it];
        }
        return ans;
    }
};