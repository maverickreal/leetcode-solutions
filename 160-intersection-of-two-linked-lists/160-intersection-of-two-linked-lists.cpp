class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ll sza = 0, szb = 0;
        auto ita = headA, itb = headB;
        while (ita) {
            ++sza;
            ita = ita->next;
        }
        while (itb) {
            ++szb;
            itb = itb->next;
        }
        if (szb > sza) {
            sza += szb;
            szb = sza - szb;
            sza -= szb;
            ita = headB;
            itb = headA;
        }
        else {
            ita = headA;
            itb = headB;
        }
        ll dif = sza - szb;
        while (dif--) {
            ita = ita->next;
        }
        while (ita && itb && ita != itb) {
            ita = ita->next;
            itb = itb->next;
        }
        return ita;
    }
};