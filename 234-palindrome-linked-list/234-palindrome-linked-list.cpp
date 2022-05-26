class Solution {
    typedef long long ll;
    typedef vector<ll> vi;
#define endl '\n'
#define ln ListNode
#define tn treeNode
    const ll mod = 1e9;
public:
    ln* reverse(ln* nd) {
        ln* pre = nullptr, *post = nd;
        while (post) {
            ln* nxt = post->next;
            post->next = pre;
            pre = post;
            post = nxt;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
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
        pre=head;
        while (post && pre) {
            if (pre->val != post->val){
                cout<<pre->val<<' '<<post->val<<endl;
                return false;
            }
            pre = pre->next;
            post = post->next;
        }
        return true;
    }
};