class Solution {
public:
    int binaryGap(int n) {
        if(n<3)
            return 0;
        int cnt=0, res=0;
        bool pre=false;
        while(n){
            if(n&1){
                if(pre)
                    res=max(res, cnt);
                else
                    pre=true;
                cnt=1;
            }
            else
                ++cnt;
            n>>=1;
        }
        return res;
    }
};