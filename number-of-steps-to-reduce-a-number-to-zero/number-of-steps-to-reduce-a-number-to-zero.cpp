class Solution {
public:
    int numberOfSteps(int n) {
        int res = 0;
        while (n > 0) {
            if (n & 1 && n != 1)
                res += 2;
            else
                ++res;
            n >>= 1;
        }
        return res;
    }
};