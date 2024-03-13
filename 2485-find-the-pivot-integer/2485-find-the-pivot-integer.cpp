class Solution {
public:
    int pivotInteger(int n) {
        for(int i = 1;i <= n;++i){
            int sum1 = get_sum(i),sum2 = get_sum(n) - get_sum(i - 1);
            if(sum1 == sum2) return i;
        }
        return -1;
    }
    int get_sum(int n){
        return n * (n + 1) / 2;
    }
};