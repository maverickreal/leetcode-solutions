class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll ans = 0;
    ll func(TreeNode* nd) {
        ll res = 0, ret = 0;
        if (!nd) {
            return ret;
        }
        ll l = func(nd->left), r = func(nd->right);
        if (nd->left && nd->left->val == nd->val) {
            res += l + 1;
            ret = max(ret, 1 + l);
        }
        if (nd->right && nd->right->val == nd->val) {
            res += r + 1;
            ret = max(ret, 1 + r);
        }
        ans = max({ ret,ans, res });
        return ret;
    }
    int longestUnivaluePath(TreeNode* root) {
        func(root);
        return ans;
    }
};