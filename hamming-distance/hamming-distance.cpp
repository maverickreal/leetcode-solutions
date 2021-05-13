class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        x ^= y;
        while (x) {
            res += x & 1;
            x >>= 1;
        }
        return res;
    }
};