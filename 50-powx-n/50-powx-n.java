class Solution {
    static private double func(double x, long n, double res){
        if(n==0)
            return res;
        //System.out.println(res+"    "+n);
        if ((n & 1) == 1){
            res *= x;
            --n;
        }
        else{
        x*=x;
        n >>= 1;
        }
        return func(x, n, res);
    }
    
        public double myPow(double x, long n) {
            if(n==0)
                return 1;
            if(n==1 || x==0 || x==1)
                return x;
            boolean fl=n<0;
            if(fl)
                n=-n;
            //System.out.println(n+" ----");
            double res=func(x, n, 1);
            if(fl)
                res=1/res;
            return res;
    }
}