class Solution {
  #define nd TreeNode
public:
  int res=0;
  void func(nd*rt){
    if(!rt)
      return;
    ++res;
    func(rt->left);
    func(rt->right);
    }
    int countNodes(TreeNode* rt) {
        func(rt);
        return res;
    }
};