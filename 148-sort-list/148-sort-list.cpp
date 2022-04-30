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
    #define ln ListNode
typedef long long ll;
#define endl '\n'
const ll mod = 1e9 + 7;

ln* merge(ln* x, ln* y) {
    ln* node = new ln(), * head = node;
    while (x && y) {
        if (x->val < y->val) {
            head->next = x;
            x = x->next;
        }
        else {
            head->next = y;
            y = y->next;
        }
        head = head->next;
    }
    if (x) head->next = x;
    if (y) head->next = y;
    return node->next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head ->next)
        return head;
    ln* pre = head, * post = head;
    ll i = -1;
    while (post->next) {
        ++i;
        post=post->next;
        if (i & 1)
            pre = pre->next;
    }
    post = pre->next;
    pre->next = nullptr;
    return merge(sortList(head), sortList(post));
}
};