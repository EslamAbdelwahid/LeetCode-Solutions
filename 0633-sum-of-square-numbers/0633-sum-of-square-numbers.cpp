class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i = 0;i <= min(c, 100000);++i){
            long long a = i * i;
            long long b = (long long)c - a;
            long double sq = sqrt(b);
            sq = floor(sq);
            if((sq * sq == b) && a + sq * sq == c) return true;
        }
        return false;
    }
};