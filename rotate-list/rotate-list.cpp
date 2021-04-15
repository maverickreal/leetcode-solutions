class Solution {
  #define ln ListNode
public:
    ListNode* rotateRight(ListNode* nd, int k) {
        if(!nd or !nd->next or !k)
          return nd;
        auto it=nd;
        vector<ln*>v;
        while(it){
          v.push_back(it);
          it=it->next;
        }
        int sz=v.size();
        int n=sz-(k%sz);
        if(n==sz)
            return nd;
        if(n)
          v[n-1]->next=nullptr;
        v[sz-1]->next=v[0];
        return v[n];
    }
};