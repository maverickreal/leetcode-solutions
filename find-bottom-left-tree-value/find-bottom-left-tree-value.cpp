class Solution {
  #define tn TreeNode
public:
  pair<int,int>res={-1,-1};
  void func(tn*rt,int lev){
    if(!rt->left and !rt->right){
      if(lev>res.second)
        res={rt->val,lev};
      return;
    }
    if(rt->left)
      func(rt->left,1+lev);
    if(rt->right)
      func(rt->right,lev+1);
  }
    int findBottomLeftValue(TreeNode* rt) {
        func(rt,0);
        return res.first;
    }
};