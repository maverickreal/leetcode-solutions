class Solution {
public:
    int search(vector<int>&v, int tar) {
        int s=0,e=v.size()-1,m=s+((e-s)>>1);
        while(s<e){
            int m=s+((e-s)>>1);
            if(v[m]==tar)
                break;
            if(v[m]>tar)
                e=m-1;
            else
                s=m+1;
        }
        m=s+((e-s)>>1);
        if(m<0 || m>=v.size())
            m=0;
        return (v[m]==tar?m:-1);
    }
};