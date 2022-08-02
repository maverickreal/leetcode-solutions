class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    unordered_map<ll, ll>preump, inump;
    ll n;
    TreeNode* func(const vi(int)& pre, const  vi(int)& in, ll start, ll end) {
        if (start > end) {
            return nullptr;
        }
        ll it = -1, pos = LLONG_MAX;
        for (ll i = start;i <= end;++i) {
            if (it == -1 || preump[in[i]] < pos) {
                it = i;
                pos = preump[in[i]];
            }
        }
        TreeNode* root = new TreeNode(in[it]);
        root->left = func(pre, in, start, it - 1);
        root->right = func(pre, in, it + 1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        n = pre.size();
        for (ll i = 0;i < n;++i) {
            preump[pre[i]] = i;
            inump[in[i]] = i;
        }
        return func(pre, in, 0, n - 1);
    }
};