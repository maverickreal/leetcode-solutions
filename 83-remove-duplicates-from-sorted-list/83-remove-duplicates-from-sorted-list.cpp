class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!(head && head->next)) return head;
        for (ListNode* it = head;it;it = it->next) {
            ListNode* ti = it->next;
            for (;ti && ti->val == it->val;ti = ti->next);
            it->next = ti;
        }
        return head;
    }
};