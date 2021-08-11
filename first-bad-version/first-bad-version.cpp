// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int e) {
        if(!e)
          return 1;
        int s=1,res=INT_MAX;
while(s<=e){
  int m=s-(s-e)/2;
  if(isBadVersion(m)){
    res=min(res,m);
    e=m-1;
  }
  else
    s=m+1;
}
return res;
    }
};