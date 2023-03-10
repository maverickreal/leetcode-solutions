class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>&v) {
        int sz=v.size(), i=0, j=sz-1, ans=sz-1;
        for(i=0;i<sz-1;++i){
          if(v[i]>v[i+1])
            break;
        }
        if(i==sz-1)
          return 0;
        for(j=sz-1;j>i;--j){
          if(v[j]<v[j-1])
            break;
        }
        ans=min({ans, sz-i-1, j});
        for(int l=0; l<=i && j<sz; ++l){
            if(v[l]<=v[j]){
                ans=min(ans, j-l-1);
            }
            else{
                --l, ++j;
            }
        }
        return ans;
    }
};