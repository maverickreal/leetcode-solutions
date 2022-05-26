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
#define ln ListNode
#define tn treeNode
typedef vector<ll> vi;
#define endl '\n'
const ll mod = 1e9;

ln* reverse(ln* nd) {
    ln* pre = nullptr, * post = nd;
    while (post) {
        ln* nxt = post->next;
        post->next = pre;
        pre = post;
        post = nxt;
    }
    return pre;
}

void reorderList(ListNode* head) {
    ln* pre = head, * post = head;
    bool fl = false;
    while (post->next) {
        post = post->next;
        if (fl) {
            fl = false;
            pre = pre->next;
        }
        else
            fl = true;
    }
    post = reverse(pre->next);
    pre->next = nullptr;
    pre = head;
    while (pre && post) {
        ln* nxtPre = pre->next;
        pre->next = post;
        pre = post;
        post = nxtPre;
    }
    if (pre)
        pre->next = nullptr;
    if (post)
        post->next = nullptr;
}
};