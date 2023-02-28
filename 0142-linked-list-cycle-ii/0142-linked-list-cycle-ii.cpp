/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
#define ln ListNode
ListNode *detectCycle(ListNode *head) {
    ln*sp=head, *fp=head;
    bool meetCnt=0;
    while(fp){
        if(sp==fp){
            if(!meetCnt){
                meetCnt=1;
            }
            else{
                break;
            }
        }
        sp=sp->next, fp=fp->next;
        if(fp){
            fp=fp->next;
        }
    }
    if(!fp){
        return nullptr;
    }
    sp=head;
    while(sp!=fp){
        sp=sp->next, fp=fp->next;
    }
    return sp;
}
};