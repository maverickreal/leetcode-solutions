class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)
        return false;
        if(n<4)
            return (n==1);
        bool res=!((n&1) || (n&(n-1)));
        int pos=0;
        while(n){
            ++pos;
            n>>=1;
        }
        return (res && (pos&1));
    }
};