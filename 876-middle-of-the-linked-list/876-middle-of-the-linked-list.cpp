/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    #define ln ListNode
public:
    ListNode* middleNode(ListNode* head) {
        ln*pre=head, *post=head;
        int sz=0;
        while(post->next){
            ++sz;
            if((sz-1)&1)
                pre=pre->next;
            post=post->next;
        }
        if(sz&1)
            pre=pre->next;
        return pre;
    }
};