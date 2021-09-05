class Solution {
public:
    int maxProfit(vector<int>&v) {
        int i=0,sz=v.size(),res=0;
        for(int j=1;j<sz;++j){
            if(v[j]<v[i]){
                i=j;
                continue;
            }
            int k=j;
            while(++k<sz && v[k]>v[k-1]);
            --k;
            res+=v[k]-v[i];
            i=k,j=k;
        }
        return res;
    }
};