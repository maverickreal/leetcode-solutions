class Solution {
    #define tn TreeNode
public:
    vector<int> postorderTraversal(TreeNode* rt) {
        vector<int>res;
if(!rt)
  return res;
stack<tn*>st;
st.push(rt);
while(!st.empty()){
  tn* tmp=st.top();
  if(!tmp){
    st.pop();
    res.push_back(st.top()->val);
    st.pop();
  }
  else{
    st.push(nullptr);
    if(tmp->right)
      st.push(tmp->right);
    if(tmp->left)
      st.push(tmp->left);
  }
}
return res;
    }
};