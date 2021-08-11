class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> res;
if(v.size()<3)
 return res;
sort(v.begin(),v.end());
for(int i=0;i<v.size()-2;++i){
  if(!i or v[i]!=v[i-1]){
  int sum=0-v[i];
  int l=i+1,r=v.size()-1;
  while(l<r){
    int tmp=v[l]+v[r];
    if(tmp==sum){
      res.push_back({v[i],v[l],v[r]});
    while(l<r and v[l]==v[l+1])
      ++l;
    ++l;
    while(l<r and v[r]==v[r-1])
      --r;
    --r;
  }
  else if(tmp>sum)
    --r;
  else
    ++l;
  }
}
}
return res;
    }
};