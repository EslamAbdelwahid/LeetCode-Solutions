class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> arr = score;
        sort(arr.begin(), arr.end(), greater<int>()); 
        unordered_map < int , int > rank;
        vector<string> ans;
        for(int i = 0;i < arr.size();++i){
            rank[arr[i]] = i;
        }
        for(auto &i : score){
            if(rank[i] > 2){
                ans.push_back(to_string(rank[i] + 1));
            }else if(rank[i] == 0){
                ans.push_back("Gold Medal");
            }else if(rank[i] == 1){
                ans.push_back("Silver Medal");
            }else{
                ans.push_back("Bronze Medal");
            }
        }
        return ans ;
    }
};