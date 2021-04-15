class Solution {
  #define ln ListNode
public:// 1 2 3
    ListNode* swapPairs(ListNode* hd) {
        if(!hd or !hd->next)
          return hd;
        ln*par=nullptr,*it=hd,*res=hd->next;
        while(it){
          if(par)
            par->next=it->next?it->next:it;
          ln*ti=nullptr;
          if(it->next){
            ti=it->next->next;
            it->next->next=it;
          }
          par=it;
          it=ti;
        }
        if(par)
          par->next=nullptr;
        return res;
    }
};
