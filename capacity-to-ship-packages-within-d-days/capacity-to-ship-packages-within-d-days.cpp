class Solution {
public:
  int sz;
  bool func(const int&c,const vector<int>&v,int d){
    int cap=c;
      for(int k=0;k<sz;++k){
        if(c==11)
            cout<<cap<<' '<<v[k]<<' '<<d<<'\n';
        if(cap<v[k]){
          if(d<2)
            return false;
          --d;
          cap=c-v[k];
        }
        else
          cap-=v[k];
      }
    return true;
  }
    int shipWithinDays(vector<int>&w,int&d) {
      sz=w.size();
      int res,mx=0;
      mx=accumulate(w.begin(),w.end(),mx);
      res=mx;
      int mn=*max_element(w.begin(),w.end());
      //if(d==1)
        //return res;
      while(mn<=mx){
        int md=mn+((mx-mn)>>1);
        if(func(md,w,d)){
          res=min(res,md);
          mx=md-1;
        }
      else{
        //cout<<"false for "<<md<<'\n';
        mn=md+1;
      }
    }
    return res;
  }
};