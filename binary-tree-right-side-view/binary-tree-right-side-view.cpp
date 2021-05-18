class Solution {
  #define nd TreeNode
public:
  vector<int>res;
  void func(nd*rt,int d){
    if(!rt)
      return;
    if(d>=res.size())
      res.push_back(rt->val);
    func(rt->right,d+1);
    func(rt->left,d+1);
  }
    vector<int> rightSideView(TreeNode* rt) {
        if(rt)  
            func(rt,0);
        return res;
    }
};