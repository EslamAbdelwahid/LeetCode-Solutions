class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<long double, pair<int,int>>> v;
        for(int i = 0;i < arr.size();++i){
            for(int j = i + 1;j < arr.size();++j){
                long double x = (arr[i] * 1.0 / arr[j] * 1.0);
                v.push_back({x, {arr[i], arr[j]}});
            }
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        ans.push_back(v[k - 1].second.first);
        ans.push_back(v[k - 1].second.second);
        return ans ;
    }
};