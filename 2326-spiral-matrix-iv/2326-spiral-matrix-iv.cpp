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
typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define pb push_back
#define ln ListNode
const ll mod = 1e9 + 7;
const char nl = '\n';
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    ll p = -1, cnt = 0;
    vi(vi(ll))res(m, vi(ll)(n, -1));
    while (cnt < (m * n)) {
        ++p;
        for (ll i = 0;i < n - (2 * p);++i) {
            if (!head)
                return res;
            res[p][p + i] = head->val;
            head = head->next;
            ++cnt;
        }
        for (ll i = 1;i < m - 2 * p;++i) {
            if (!head)
                return res;
            res[p + i][n - 1 - p] = head->val;
            head = head->next;
            ++cnt;
        }
        for (ll i = n - p - 2;i >= p;--i) {
            if (!head)
                return res;
            res[m - 1 - p][i] = head->val;
            head = head->next;
            ++cnt;
        }
        for (ll i = m - p - 2;i >= p + 1;--i) {
            if (!head)
                return res;
            res[i][p] = head->val;
            head = head->next;
            ++cnt;
        }
    }
    return res;
}
};