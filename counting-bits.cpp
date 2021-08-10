class Solution {
public:
  int func(int i){
    int res=0;
    while(i){
      if(i&1)
        ++res;
      i>>=1;
    }
    return res;
  }
    vector<int> countBits(int num) {
        vector<int>res(num+1,0);
        for(int i=1;i<num+1;++i){
          if(res[i])
            continue;
          int tmpres=func(i);
          //cout<<i<<' '<<tmpres<<'\n';
          int j=i;
          while(j<num+1){
            res[j]=tmpres;
            j<<=1;
          }
        }
        return res;
    }
};