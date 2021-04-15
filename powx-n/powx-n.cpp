class Solution {
public:
    double myPow(double x, int nt) {
        if(!x or x==1)
            return x;
        if(!nt)
            return 1;
        if(nt==1)
            return x;
        bool fl=nt<0;
        long n=nt;
        if(fl)
          n*=-1;
        double res=1;
        while(n){
          if(n&1){
            res*=x;
            --n;
            continue;
          }
          x*=x;
          n>>=1;
        }
        if(fl)
          res=1/res;
        return res;
    }
};