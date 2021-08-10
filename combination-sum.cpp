class Solution {
public:
    void back(vector<vector<int>>&res,vector<int>&v,vector<int> cur,int tar,int in){
  if(tar<1){
    if(!tar)
      res.push_back(cur);
    return;
  }
  for(int i=in;i<v.size();++i){
    cur.push_back(v[i]);
    back(res, v,cur,tar-v[i],i);
    cur.pop_back();
  }
}
    vector<vector<int>> combinationSum(vector<int>& v, int tar) {
      vector<vector<int>> res;
back(res,v,{},tar,0);
return res;  
    }
};