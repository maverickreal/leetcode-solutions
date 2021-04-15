class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;
        long i=1;
        while(i*i<=x)
            ++i;
        return i*i==x?i:i-1;
    }
};