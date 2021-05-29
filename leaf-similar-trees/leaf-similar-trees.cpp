class Solution {
public:
    #define nd TreeNode
    void func(nd*rt,vector<int>&v){
  if(rt->left==NULL and rt->right==NULL)
    v.push_back(rt->val);
  else{
    if(rt->left!=NULL)
      func(rt->left,v);
    if(rt->right!=NULL)
      func(rt->right,v);
  }
}
    bool leafSimilar(TreeNode* rt1, TreeNode* rt2) {
        vector<int>v;
        func(rt1,v);
func(rt2,v);
if(v.size()%2)
  return false;
int i=0,j=v.size()/2;
while(j!=v.size()){
  if(v[i]!=v[j])
    return false;
  ++i;
  ++j;
}
return true;
    }
};