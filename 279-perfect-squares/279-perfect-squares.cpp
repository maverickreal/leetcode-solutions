class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(ll)v;
    vi(ll)dp;
    ll func(ll n) {
        if (n < 0) {
            return LLONG_MAX;
        }
        if (n == 0) {
            return 0;
        }
        if (dp[n] == -1) {
            dp[n] = LLONG_MAX;
            for (ll it : v) {
                ll rec = func(n - it);
                if (rec < LLONG_MAX) {
                    dp[n] = min(dp[n], rec + 1);
                }
            }
        }
        return dp[n];
    }
    int numSquares(int n) {
        dp.resize(n + 1, -1);
        for (ll i = 1;i * i <= n;++i) {
            v.pb(i * i);
        }
        ll ans = LLONG_MAX;
        for (ll it : v) {
            ans = min(ans, 1 + func(n - it));
        }
        return ans;
    }
};