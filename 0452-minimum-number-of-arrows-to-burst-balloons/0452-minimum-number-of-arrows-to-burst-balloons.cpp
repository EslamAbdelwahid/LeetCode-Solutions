class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<pair<int,int>>ans;
        ans.push_back({points[0][0], points[0][1]});
        for(int i = 1;i < points.size();++i){
            int l = ans.back().first, r = ans.back().second;
            if(points[i][0] >= l && points[i][0] <= r){
                ans.pop_back();
                ans.push_back({min(l, points[i][0]), min(r, points[i][1])});
            }else{
                ans.push_back({points[i][0], points[i][1]});
            }
        }
        return ans.size();
    }
};