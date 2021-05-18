class Solution {
public:
    int func(vector<int>&dp,vector<int>&v,int n){
if(n>=v.size())
  return 0;
dp[n]=dp[n]==-1?max(v[n]+func(dp,v,n+2),func(dp,v,n+1)):dp[n];
return dp[n];
}
    int rob(vector<int>& v) {
    vector<int> dp;
for(int i=0;i<v.size()+1;++i)
  dp.push_back(-1);
return func(dp,v,0);

    }
};