class Solution {
public://[[-1],[3,2],[-3,1,-1]]
map<pair<int,int>,int>dp;
int func(vector<vector<int>>&tri,int i,int j){
  if(i>=tri.size())
    return 0;
  j=j<0?0:j;
  int szt=tri[i].size();
  j=j>=szt?szt-1:j;
  if(dp.find({i,j})==dp.end())
    dp[{i,j}]=min(func(tri,i+1,j),func(tri,i+1,j+1))+tri[i][j];
  return dp[{i,j}];
}
    int minimumTotal(vector<vector<int>>& tri) {
      int sz=tri[0].size(),res=INT_MAX;
        for(int i=0;i<sz;++i)
          res=min(res,func(tri,0,i));
        return res;
    }
};