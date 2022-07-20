class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next)
            return nullptr;
        ListNode* pre = head, * cur = head;
        while (cur) {
            pre = pre->next;
            cur = cur->next;
            if (cur)
                cur = cur->next;
            if (pre == cur)
                break;
        }
        if (!cur)
            return nullptr;
        pre = head;
        while (pre != cur) {
            pre = pre->next;
            cur = cur->next;
        }
        return pre;
    }
};