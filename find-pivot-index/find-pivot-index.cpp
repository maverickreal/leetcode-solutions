class Solution {
public:
    int pivotIndex(vector<int>&v) {
        int sz=v.size();
        for(int i=1;i<sz;++i)
            v[i]+=v[i-1];
        for(int i=0;i<sz;++i){
            int l=i?v[i-1]:0;
            int r=v.back()-v[i];
            if(l==r)
                return i;
        }
        return -1;
    }
};