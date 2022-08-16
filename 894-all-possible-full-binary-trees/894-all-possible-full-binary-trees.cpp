class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(TreeNode*) func(ll n) {
        if (n == 1) {
            return { new TreeNode(0) };
        }
        vi(TreeNode*)res;
        for (ll i = 1;i < n;i += 2) {
            auto l = func(i), r = func(n - i-1);
            for (auto x : l) {
                for (auto y : r) {
                    auto root = new TreeNode(0);
                    root->left = x;
                    root->right = y;
                    res.pb(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vi(TreeNode*)ans;
        if (n % 2 == 0) {
            return ans;
        }
        if (n == 1) {
            return { new TreeNode(0) };
        }
        for (ll i = 1;i < n;i += 2) {
            auto l = func(i), r = func(n - i-1);
            for (auto x : l) {
                for (auto y : r) {
                    TreeNode* nd = new TreeNode(0);
                    nd->left = x;
                    nd->right = y;
                    ans.pb(nd);
                }
            }
        }
        return ans;
    }
};