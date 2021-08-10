class Solution {
  #define ln ListNode
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ln*it=l1;
      int car=0;
      while(it or l2){
        int sum=car;
        if(!l2){
          sum+=it->val;
          car=sum/10;
          it->val=sum%10;
          if(!car)
            break;
          if(!it->next)
            it->next=new ln;
          it=it->next;
          continue;
        }
        sum+=l2->val;
        l2=l2->next;
        sum+=it->val;
        car=sum/10;
        if(!it->next and (l2 or car))
          it->next=new ln;
        it->val=sum%10;
        it=it->next;
      }
      return l1;
    }
};