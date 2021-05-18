class Solution {
  #define ln ListNode
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ln*>st1,st2;
        ln*it=l1;
        while(it){
          st1.push(it);
          it=it->next;
        }
        it=l2;
        while(it){
          st2.push(it);
          it=it->next;
        }
        it=nullptr;
        int car=0;
        while(!st1.empty() or !st2.empty()){
          if(st1.empty()){
            while(!st2.empty()){
              car+=st2.top()->val;
              st2.pop();
              ln*g=new ln(car%10);
              g->next=it;
              it=g;
              car/=10;
            }
            while(car){
              ln*g=new ln(car%10);
              car/=10;
              g->next=it;
              it=g;
            }
            break;
          }
          if(st2.empty()){
            while(!st1.empty()){
              car+=st1.top()->val;
              st1.pop();
              ln*g=new ln(car%10);
              g->next=it;
              it=g;
              car/=10;
            }
            while(car){
              ln*g=new ln(car%10);
              g->next=it;
              it=g;
              car/=10;
            }
            break;
          }
          int tmp=car+st1.top()->val+st2.top()->val;
          st1.pop();
          st2.pop();
          ln*g=new ln(tmp%10);
          car=tmp/10;
          g->next=it;
          it=g;
        }
        while(car){
          ln*g=new ln(car%10);
          g->next=it;
          it=g;
          car/=10;
        }
        return it;
    }
};