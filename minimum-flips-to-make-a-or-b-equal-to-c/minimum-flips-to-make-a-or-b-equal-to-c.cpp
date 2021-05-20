class Solution {
public:
    int minFlips(int a, int b, int c) {
        short res = 0;
        while (a || b || c) {
            if ((c & 1) && !((a | b) & 1))
                ++res;
            if (!(c & 1)) {
                if (a & 1)
                    ++res;
                if (b & 1)
                    ++res;
            }
            a >>= 1, b >>= 1, c >>= 1;
        }
        return res;
    }
};