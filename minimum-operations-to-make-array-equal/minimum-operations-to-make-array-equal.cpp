class Solution {
public:
    int minOperations(int n) {
        int i = 1, j = ((n - 1) << 1) + 1, res = 0;
        while (i < j) {
            res += (j - i) >> 1;
            i += 2, j -= 2;
        }
        return res;
    }
};