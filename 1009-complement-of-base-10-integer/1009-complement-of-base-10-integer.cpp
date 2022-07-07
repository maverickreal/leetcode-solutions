class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n)
            return 1;
      int cnt=0, N=n;
        while(n){
            n>>=1;
            ++cnt;
        }
        return N^((1LL<<cnt)-1);
    }
};