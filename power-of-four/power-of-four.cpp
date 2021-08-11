class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<4)
            return n==1;
        int res=0;
        while(!(n&1)){
            ++res;
            n>>=1;
        }
              return !(res&1) && n==1;
    }
};