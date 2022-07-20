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
typedef long long ll;
#define ln ListNode

ListNode* getIntersectionNode(ListNode* x, ListNode* y) {
    ln* a = x, * b = y;
    while (a || b) {
        if (!a)
            a = x;
        if (!b)
            b = y;
        if (a == b)
            return a;
        a = a->next;
        b = b->next;
    }
    return nullptr;
}
};