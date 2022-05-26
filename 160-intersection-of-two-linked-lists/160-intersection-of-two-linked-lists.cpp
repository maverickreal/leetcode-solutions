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
#define tn treeNode
typedef vector<ll> vi;
#define endl '\n'
const ll mod = 1e9;

ListNode* getIntersectionNode(ListNode* x, ListNode* y) {
    ln* a = x, * b = y;
    while (true) {
        if (!a && b)
            a = x;
        if (!b && a)
            b = y;
        if (!(a || b))
            break;
        if (a == b)
            return a;
        a = a->next;
        b = b->next;
    }
    return nullptr;
}
};