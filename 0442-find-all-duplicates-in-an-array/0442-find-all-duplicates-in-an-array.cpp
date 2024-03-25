class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>fre(1e5 + 2,0), ans;
        for(auto &i : nums){
            fre[i]++;
            if(fre[i] == 2) ans.push_back(i);
        }
        return ans;
    }
};