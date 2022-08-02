class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(ll)ump;
    ll n;
    TreeNode* func(const vi(int)& pre, const vi(int)& post, ll start, ll end) {
        if (start > end) {
            return nullptr;
        }
        TreeNode* nd = new TreeNode(post[end]);
        if(start==end){
            return nd;
        }
        ll it = -1, pos = LLONG_MAX;
        for (ll i = start;i < end;++i) {
            if (it == -1 || ump[post[i]] < pos) {
                it = i;
                pos = ump[post[i]];
            }
        }
        nd->left = func(pre, post, start, it);
        nd->right = func(pre, post, it + 1, end - 1);
        return nd;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        n = post.size();
        ump.resize(n + 1);
        for (ll i = 0;i < n;++i) {
            ump[pre[i]] = i;
        }
        return func(pre, post, 0, n - 1);
    }
};