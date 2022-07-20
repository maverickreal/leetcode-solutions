class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(ll)dp;
    ll func(ll m) {
        if (m < 2)
            return 1;
        if (dp[m] == -1) {
            dp[m] = 0;
            for (ll i = 1;i <= m;++i) {
                dp[m] += func(i - 1) * func(m - i);
            }
        }
        return dp[m];
    }
    int numTrees(int n) {
        dp.resize(n + 1, -1);
        ll res = 0;
        for (ll i = 1;i <= n;++i) {
            res += func(i - 1) * func(n - i);
        }
        return res;
    }
};