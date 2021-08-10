class Solution {
public:
    int minCostClimbingStairs(vector<int>& v) {
        vector<int>dp(v.size()+1);
fill(dp.begin(),dp.end(),0);
for(int i=2;i<=dp.size()-1;++i){
  dp[i]=min(dp[i-1]+v[i-1],dp[i-2]+v[i-2]);
}
return dp[dp.size()-1];
    }
};