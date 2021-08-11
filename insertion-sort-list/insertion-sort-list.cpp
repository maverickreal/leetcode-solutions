class Solution {
  #define nd ListNode
public:
  nd*hd,*res;
  void ins(nd*par,nd*it,nd*child){
    nd*loc1=nullptr,*loc2=hd;
    while(loc2 and loc2->val<it->val){
      loc1=loc2;
      loc2=loc2->next;
    }
    if(loc1)
      loc1->next=it;
    //if(loc2)
    it->next=loc2;
      //cout<<"x  "<<(loc1?loc1->val:0)<<' '<<it->val<<' '<<(loc2?loc2->val:0)<<'\n';
    par->next=child;
    hd=hd->val>=res->val?res:hd;
  }
    ListNode* insertionSortList(ListNode* head) {
      if(!head or !head->next)
        return head;
      hd=head,res=head;
        nd*par=head,*it=head->next,*child=it->next;
        while(it){
            //cout<<(par?par->val:0)<<' '<<it->val<<' '<<(child?child->val:0)<<'\n';
          //cout<<it->val<<' ';
          if(res->val>=it->val)
            res=it;
          bool fl=false;
          if(it->val<=par->val){
            fl=true;
            ins(par,it,child);
          }
          if(!fl)
            par=par?par->next:it;
          it=child;
          child=child?child->next:nullptr;
        }
        //cout<<(par?par->val:0)<<' '<<(it?it->val:0)<<' '<<(child?child->val:0);
        return res;
    }
};