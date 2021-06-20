class Solution {
public:
  int sz;
  bool func(const int&i,int h,const vector<int>&p){
    for(const int&j:p){
      if(h<1)
        return false;
      h-=j/i;
      if(j%i)
        --h;
    }
    return h>-1;
  }
    int minEatingSpeed(const vector<int>& p,const int&h) {
      sz=p.size();//1
      int res,mn=1,mx=0;
      for(const int&i:p)
        mx=max(mx,i);
      res=mx;//1
      while(mn<=mx){
      int md=mn+((mx-mn)>>1);
      if(func(md,h,p)){
          res=min(res,md);
          mx=md-1;
        }
        else
          mn=md+1;
      }
      return res;
    }
};