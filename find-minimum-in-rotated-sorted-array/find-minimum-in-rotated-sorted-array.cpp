class Solution {
public:
  int res=INT_MAX;
  void func(vector<int>&v,int b,int e){
    if(b>e)
      return;
    int m=(b+e)>>1;
    res=min(res,v[m]);
    func(v,b,m-1);
    func(v,m+1,e);
  }
    int findMin(vector<int>& nums) {
        func(nums,0,nums.size()-1);
        return res;
    }
};