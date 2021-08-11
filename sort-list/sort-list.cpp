class Solution {
  #define ln ListNode
public:
  static bool alpha(ln*a,ln*b){
    return a->val<b->val;
  }
    ListNode* sortList(ListNode* hd) {
        if(!hd)
          return hd;
        vector<ln*>st;
        while(hd){
          st.push_back(hd);
          hd=hd->next;
        }
        sort(st.begin(),st.end(),alpha);
        int sz=st.size();
        for(int i=0;i<sz-1;++i)
          st[i]->next=st[i+1];
        st[sz-1]->next=NULL;
        return st[0];
    }
};