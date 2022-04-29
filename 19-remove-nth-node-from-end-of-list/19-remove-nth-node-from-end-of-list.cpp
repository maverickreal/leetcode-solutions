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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ln* left=nullptr, *pre=head, *post=head;
        for(int i=0;i<n-1;++i)
            post=post->next;
        while(post->next){
            left=pre;
            pre=pre->next;
            post=post->next;
        }
        if(!left)
            return pre->next;
        left->next=pre->next;
        return head;
    }
};