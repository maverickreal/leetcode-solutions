class Solution {
  #define ln ListNode
public:
    ListNode* oddEvenList(ListNode* hd) {
        if(!hd || !hd->next)
          return hd;
        ln*ti=hd->next,*it=hd,*tmp=ti;
        while(it->next || ti->next){
          if(it->next){
            it->next=it->next->next;
            if(it->next)
              it=it->next;
          }
          if(ti->next){
            ti->next=ti->next->next;
            if(ti->next)
              ti=ti->next;
          }
        }
        it->next=tmp;
        ti->next=nullptr;
        return hd;
    }
};