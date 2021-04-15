/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    #define tn TreeNode
public:
    tn* build(vector<int>&in,vector<int>&po,unordered_map<int,int>&ump,int st,int en,int&rt){
  if(st>en)
    return nullptr;
  tn*a=new tn(po[rt--]);
  if(st==en)
    return a;
  int cur=ump[a->val];
  a->right=build(in,po,ump,cur+1,en,rt);
  a->left=build(in,po,ump,st,cur-1,rt);
  return a;
}
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        int sz=in.size();
if(!sz)
  return nullptr;
unordered_map<int,int>ump;
for(int i=0;i<sz;++i)
  ump[in[i]]=i;
int rt=sz-1;
return build(in,po,ump,0,sz-1,rt);
    }
};