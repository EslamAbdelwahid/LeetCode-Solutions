class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        Sort(nums1);
        Sort(nums2);
        vector<int>ans;
        for(auto &i : nums1){
            auto it = lower_bound(nums2.begin(), nums2.end(), i) - nums2.begin();
            if(it < nums2.size() && nums2[it] == i){
                ans.push_back(i);
            }
        }
        vector<int>unique_ans;
        for(int i = 0;i < ans.size();++i){
            if(!(i + 1 < ans.size() && ans[i] == ans[i + 1])){
                unique_ans.push_back(ans[i]);
            }
        }
        return unique_ans;
    }
    void Sort(vector<int>&arr){
        sort(arr.begin(), arr.end());
    }
};