class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1)
            return false;
        if(n==1)
            return true;
        return !(n&1) and !(n&(n-1));
    }
};