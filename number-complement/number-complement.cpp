class Solution {
public:
    int findComplement(int n) {
        int m=n,tmp=0;
        while(m){
            ++tmp;
            m>>=1;
        }
        return n^(int)(pow(2,tmp)-1);
    }
};