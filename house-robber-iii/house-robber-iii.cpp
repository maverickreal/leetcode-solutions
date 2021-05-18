class Solution {
  #define nd TreeNode
public://[1,2,3,4]
unordered_map<nd*,int>tr,fa;
  int func(nd*rt,bool fl){
    if(!rt)
      return 0;
    tr[rt->left]=tr.find(rt->left)==tr.end()?func(rt->left,true):tr[rt->left];
    tr[rt->right]=tr.find(rt->right)==tr.end()?func(rt->right,true):tr[rt->right];
    fa[rt->left]=fa.find(rt->left)==fa.end()?func(rt->left,false):fa[rt->left];
    fa[rt->right]=fa.find(rt->right)==fa.end()?func(rt->right,false):fa[rt->right];
    if(fl)
      return fa[rt->left]+fa[rt->right]+rt->val;
    return max(max(tr[rt->left]+tr[rt->right],fa[rt->left]+fa[rt->right]),max(tr[rt->left]+fa[rt->right],tr[rt->right]+fa[rt->left]));
  }
    int rob(TreeNode* rt) {
        return max(func(rt,true),func(rt,false));
    }
};