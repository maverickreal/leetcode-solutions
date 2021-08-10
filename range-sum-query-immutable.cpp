class NumArray {
    private:
  vector<vector<int>> dp;
  bool zerocase;
public:
    NumArray(vector<int>& v) {
      if(!v.size()){
        zerocase=true;
        return;
      }
      zerocase=false;
      dp=vector<vector<int>>(v.size(),vector<int>(v.size()));
      dp[0][0]=v[0];
for(int i=0;i<v.size();++i){
  for(int j=0;j<v.size();++j){
    if(i<=j and (i or j))
      dp[i][j]=dp[i][j-1]+v[j];
}
    }
  }
    
    int sumRange(int i, int j) {
        return zerocase?0:dp[i][j];
    }
};
