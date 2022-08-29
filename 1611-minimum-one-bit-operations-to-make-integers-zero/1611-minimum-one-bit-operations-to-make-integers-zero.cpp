class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        bool oddIndex = false;
        for (int i = 0;i < 32;++i) {
            if (n & (1 << i)) {
                if (oddIndex) {
                    ans -= (1 << (i + 1)) - 1;
                }
                else {
                    ans += (1 << (i + 1))-1;
                }
                oddIndex = !oddIndex;
            }
        }
        if (!oddIndex) {
            ans *= -1;
        }
        return ans;
    }
};