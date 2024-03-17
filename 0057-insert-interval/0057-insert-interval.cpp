class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<pair<int,int>> pairs;
        int n = intervals.size();
        int a = newInterval[0], b = newInterval[1];
        bool ok =  1;
        for(int i = 0;i < n;++i){
            if(intervals[i][0] > a && ok){
                pairs.push_back({a, b});
                ok = 0;
            }
            pairs.push_back({intervals[i][0], intervals[i][1]});
        }
        if(ok){
            pairs.push_back({a, b});
        }
        vector<pair<int,int>>ans;
        ans.push_back(pairs[0]);
        for(int i = 1;i < pairs.size();++i){
            int l = ans.back().first, r = ans.back().second;
             a = pairs[i].first, b = pairs[i].second;
            if(a <= r){
                ans.pop_back();
                ans.push_back({l, max(b, r)});
            }else{
                ans.push_back({a , b});
            }
        }
        intervals.clear();
        for(auto &[l, r] : ans){
            intervals.push_back({l, r});
        }
        return intervals;
    }
};