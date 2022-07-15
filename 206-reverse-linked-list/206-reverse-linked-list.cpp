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
public:
    ListNode* reverseList(ListNode* head) {
        auto nd=head, pre=head;
        pre=nullptr;
        while(nd){
            auto nxt=nd->next;
            nd->next=pre;
            pre=nd;
            nd=nxt;
        }
        return pre;
    }
};