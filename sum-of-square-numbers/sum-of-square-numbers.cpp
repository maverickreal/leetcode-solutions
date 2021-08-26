class Solution {
public:
    bool judgeSquareSum(long long n) {
        long long i = 0, j = (long long)sqrt(n);
        while (i <= j) {
            long long val = (i * i) + (j * j);
            if (val == n) return true;
            if (val < n)
                ++i;
            else
                --j;
        }
        return false;
    }
};