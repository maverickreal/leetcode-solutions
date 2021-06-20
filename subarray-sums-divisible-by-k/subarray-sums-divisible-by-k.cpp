class Solution {
public:
    int subarraysDivByK(vector<int>&v, int k) {
        vector<int>ump(k);
        ump[0]=1;
        int sz=v.size(),t=0,res=0;
        for(int i=0;i<sz;++i){
            t+=v[i];
            //if(!v[i]%k)
              //  ++res;
            int rem=((t%k)+k)%k;
            res+=ump[rem]++;
            //cout<<t<<' '<<rem<<' '<<ump[rem]<<' '<<res<<'\n';
        }
        return res;
    }
};