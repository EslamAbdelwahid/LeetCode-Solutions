class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 1, r = 1e9, ans = 0;;
        while(l <= r){
            int mid = (l + r) / 2;
            int balls = 1, i = 0;
            while(i < n){
                auto it = lower_bound(position.begin(), position.end(), position[i] + mid) - position.begin();
                if(it < n) ++ balls;
                i = it;
            }
            if(balls >= m){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        return ans;
    }
};