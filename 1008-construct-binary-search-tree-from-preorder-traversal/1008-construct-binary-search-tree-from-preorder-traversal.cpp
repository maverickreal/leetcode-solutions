class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll n;
    TreeNode* func(vi(int)& pre, ll start, ll end) {
        if (start > end) {
            return nullptr;
        }
        TreeNode* nd = new TreeNode(pre[start]);
        if (start == end) {
            return nd;
        }
        ll nxt = -1;
        for (ll i = start;i <= end;++i) {
            if (pre[i] > pre[start]) {
                nxt = i;
                break;
            }
        }
        if (nxt == -1) {
            nxt = end + 1;
        }
        nd->left = func(pre, start + 1, nxt - 1);
        nd->right = func(pre, nxt, end);
        return nd;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        n = pre.size();
        return func(pre, 0, n - 1);
    }
};