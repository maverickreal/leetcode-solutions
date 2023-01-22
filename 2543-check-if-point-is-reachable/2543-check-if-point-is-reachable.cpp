class Solution {
public:
    bool isReachable(int x, int y) {
        return __builtin_popcount(__gcd(x, y))<2;
    }
};