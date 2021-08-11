class BSTIterator {
  #define tn TreeNode
  stack<tn*>st;
  vector<int>v;
  int pos;
public:
    BSTIterator(TreeNode* rt) {
      pos=0;
      tn*tmp=rt;
      while(tmp or !st.empty()){
        while(tmp){
          st.push(tmp);
          tmp=tmp->left;
        }
        tn*i=st.top();
        st.pop();
        v.push_back(i->val);
        tmp=i->right;
      }
    }
    
    /** @return the next smallest number */
    int next() {
      return v[pos++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return pos<v.size();
    }
};