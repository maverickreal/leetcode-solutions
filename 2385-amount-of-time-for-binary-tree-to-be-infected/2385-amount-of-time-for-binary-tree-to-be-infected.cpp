class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll bfs(TreeNode* nd) {
        ll ans = 0;
        if (nd == nullptr) {
            return ans;
        }
        list<TreeNode*>l = { nd };
        while (!l.empty()) {
            ++ans;
            ll sz = l.size();
            while (sz--) {
                auto it = l.front();
                l.pop_front();
                if (it->left) {
                    l.pb(it->left);
                }
                if (it->right) {
                    l.pb(it->right);
                }
            }
        }
        return ans;
    }
    pi func(TreeNode* root, const ll& x, ll rts, ll mts) {
        if (!root) {
            return { -1, -1 };
        }
        if (root->val == x) {
            return { 1, bfs(root) - 1 };
        }
        if (rts > -1) {
            mts = max(mts, rts);;
            mts = max(mts, func(root->left, x, rts + 1, mts).second);
            mts = max(mts, func(root->right, x, rts + 1, mts).second);
            return { rts + 1, mts };
        }
        pi l = func(root->left, x, rts, mts);
        if (l.first > -1) {
            ll ndts = l.first, mxts = max(l.second, ndts);
            if (root->right) {
                mxts = max(mxts, func(root->right, x, ndts + 1, mxts).second);
            }
            return { ndts + 1, mxts };
        }
        pi r = func(root->right, x, rts, mts);
        if (r.first > -1) {
            ll ndts = r.first, mxts = max(r.second, ndts);
            if (root->left) {
                mxts = max(mxts, func(root->left, x, ndts + 1, mxts).second);
            }
            return { ndts + 1, mxts };
        }
        return { -1, -1 };
    }
    int amountOfTime(TreeNode* root, ll x) {
        return func(root, x, -1, -1).second;
    }
};