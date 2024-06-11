class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        vector<int> fre(1001);
        for(auto &i : arr1) fre[i]++;
        for(auto &i : arr2){
            while(fre[i]) ans.push_back(i), fre[i]--;
        } 
        for(int i = 0;i <= 1000;++i){
            while(fre[i]) ans.push_back(i), fre[i]--;
        }
        return ans ;
    }
};