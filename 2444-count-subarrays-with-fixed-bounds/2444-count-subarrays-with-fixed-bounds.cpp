class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size(), l = 0;
        vector< int > nxt(n);
        int lst = n;
        for(int i = n - 1;i >= 0;--i){
            if(nums[i] < minK || nums[i] > maxK){
                lst = i;
            }
            nxt[i] = lst;
            //cout << lst << " ";
        }
      //  cout << "\n";
        multiset<int>mst;
        for(int r = 0;r < n;++r){
            if(nxt[r] == r){
                mst.clear();
                l = r + 1;
                continue;
            }
            mst.insert(nums[r]);
            while(l <= r && *mst.begin() == minK && *mst.rbegin() == maxK){
                mst.erase(mst.find(nums[l++]));
                ans += nxt[r] - r;
            }
        }
        return ans ;
    }
};