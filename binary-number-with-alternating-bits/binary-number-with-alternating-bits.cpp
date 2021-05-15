class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool fl=!(n&1);
        while(n){
            if(fl == (n&1))
                return false;
            fl=n&1;
            n>>=1;
        }
        return true;
    }
};