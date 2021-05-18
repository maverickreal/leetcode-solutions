class Solution {
public:
    int minSubArrayLen(int s, vector<int>&v) {
      int sz=v.size(),res=INT_MAX;
      for(int i=0;i<sz;++i){
        int j=i,sum=0;
        while(j<sz){
          sum+=v[j];
          if(sum>=s){
            res=min(res,j-i+1);
            if(res==1)
              return 1;
            break;
          }
          ++j;
        }
      }
      return res==INT_MAX?0:res;
    }
};