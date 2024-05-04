class Solution {
public:
    int compareVersion(string version1, string version2) {
        string a = version1, b = version2 ;
        int n  = a.size(), m = b.size();
        int i = 0, j = 0;
        while(1){
            int sum1 = 0, sum2 = 0;
            while(i < n && a[i] != '.'){
                sum1  = sum1 * 10 + (a[i] - '0'), ++i;
            }
            ++i;
            while(j < m && b[j] != '.'){
                sum2 = sum2 * 10 + (b[j] - '0'), ++j;
            }
            ++j;
            if(sum1 > sum2) return 1;;
            if(sum1 < sum2) return -1;
            if(i >= n && j >= m) break; 
        }
        return 0 ;
    }
    
    
};