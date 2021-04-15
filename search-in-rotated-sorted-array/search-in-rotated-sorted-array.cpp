class Solution {
public:
    int search(vector<int>& v, int&tar) {
      if(v.size()<3){
        if(v[0]==tar)
          return 0;
        if(v.size()>1 and v[1]==tar)
          return 1;
        return -1;
      }
        int i=0;
while(i<v.size()){
  if(v[i]==tar)
    return i;
  if(v[i]>v[i+1])
    break;
  ++i;
}
++i;
if(i>v.size()-1 or tar>v[i-1] or tar<v[i])
  return -1;
int res;
if(tar<v[0]){
  res=lower_bound(v.begin()+i,v.end(),tar)-v.begin();
  if(v[res]==tar)
    return res;
  }
  res=lower_bound(v.begin(),v.begin()+i-1,tar)-v.begin();
  return v[res]==tar?res:-1;
    }
};//3 1 1