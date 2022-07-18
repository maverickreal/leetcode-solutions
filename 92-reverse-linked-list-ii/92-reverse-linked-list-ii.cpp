class Solution {
    ListNode* reverse(ListNode* nd) {
        ListNode* pre = nullptr;
        while (nd) {
            ListNode* nxt = nd->next;
            nd->next = pre;
            pre = nd;
            nd = nxt;
        }
        return pre;
    }
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        --left;
        --right;
        if (left == right)
            return head;
        ListNode* rt = new ListNode(-1);
        rt->next = head;
        ll dif = right - left;
        ListNode* start = rt, * end = rt;
        while (left--) {
            start = start->next;
            end = end->next;
        }
        end = end->next;
        while (dif--) {
            end = end->next;
        }
        ListNode* nxt = end->next;
        end->next = nullptr;
        ListNode* cur = start->next;
        start->next = nullptr;
        start->next = reverse(cur);
        cur->next = nxt;
        return rt->next;
    }
};