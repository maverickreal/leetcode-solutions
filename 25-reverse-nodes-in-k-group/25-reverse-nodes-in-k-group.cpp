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
typedef long long ll;
#define endl '\n'
const ll mod = 1e9 + 7;
    #define ln ListNode

ln* rotate(ln* head) {
    ln* node = head, * pre = new ln();
    pre->next = head;
    while (node) {
        ln* nxt = node->next;
        node->next = pre;
        pre = node;
        node = nxt;
    }
    return pre;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || !head->next || k==1)
        return head;
    ll i = 0;
    ln* tmp = new ln();
    tmp->next=head;
    ln* ptr = head, * pre = tmp;
    while (ptr) {
        ++i;
        if (!(i%k)) {
            ln* nxt = ptr->next;
            ptr->next = nullptr;
            ptr = pre->next;
            pre->next = rotate(pre->next);
            ptr->next = nxt;
            pre=ptr;
            ptr=nxt;
        }
        else
            ptr = ptr->next;
    }
    return tmp->next;
}
};