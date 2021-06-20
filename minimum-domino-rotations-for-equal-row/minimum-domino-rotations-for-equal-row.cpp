class Solution {
public:
    int func(vector<int> a,vector<int> b){
        int sz=a.size(),res=0;
        for(int i=1;i<sz;++i){
            if(a[i]!=a[0]){
                if(b[i]==a[0]){
                    a[i]=a[0];
                    ++res;
                }
                 else{
                    res=-1;
                    break;
                }
            }
        }
        return res;
    }
    int minDominoRotations(vector<int>&a, vector<int>&b) {
        int r1=func(a,b);
        if(!r1)
            return r1;
        if(r1==-1)
            r1=INT_MAX;
        int r2=func(b,a);
        if(!r2)
            return r2;
        if(r2==-1)
            r2=INT_MAX;
        a[0]+=b[0];
        b[0]=a[0]-b[0];
        a[0]-=b[0];
        int r3=func(a,b);
        if(r3==-1)
            r3=INT_MAX;
        else
            ++r3;
        int r4=func(b,a);
        if(r4==-1)
            r4=INT_MAX;
        else
            ++r4;
        int res=min(min(r1,r2),min(r3,r4));
        return res==INT_MAX?-1:res;
    }
};