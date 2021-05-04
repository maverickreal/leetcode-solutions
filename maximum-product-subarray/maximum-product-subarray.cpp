class Solution {
public:
    int maxProduct(vector<int>&v) {
        int sz=v.size();
        if(!sz)
          return 0;
        int res=v[0],mxcur=v[0],mncur=v[0];
        for(int i=1;i<sz;++i){
          int tmp1=mxcur*v[i],tmp2=mncur*v[i];
          mxcur=max(v[i],max(tmp1,tmp2));
          mncur=min(v[i],min(tmp1,tmp2));
          res=max(res,mxcur);
        }
        return res;
    }
};