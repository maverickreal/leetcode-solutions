class Solution {
public:
    int xorOperation(int n, int start) {
        int res = start;
        for (int i = 1;i < n;++i)
            res ^= start + (i << 1);
        return res;
    }
};