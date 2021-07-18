class Solution {
#define ln ListNode
public:
    ListNode* reverseKGroup(ListNode* hd, int k) {
        ln* nd = hd, * pre = nullptr, * res = pre;
        bool fl = true;
        int cnt = 0;
        vector<ln*>v;
        while (nd) {
            v.push_back(nd);
            if (++cnt == k) {
                if (fl) {
                    fl = false;
                    res = nd;
                }
                ln* nxt = nd->next;
                for (int i = v.size() - 1;i > 0;--i)
                    v[i]->next = v[i - 1];
                if (pre)
                    pre->next = v.back();
                v.front()->next = nxt;
                nd = nxt;
                pre = v.front();

                /*  while (s != nd) {
                     ln* tmp = s->next;
                     s->next = nxt;
                     nxt = s;
                     s = tmp;
                 } */
                cnt = 0;
                v.clear();
            }
            else
                nd = nd->next;
        }
        ln* it = res;
        while (it) {
            cout << it->val << ' ';
            it = it->next;
        }
        return res;
    }
};