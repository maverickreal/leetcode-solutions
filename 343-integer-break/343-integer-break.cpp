class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(ll)dp;
    ll func(ll n) {
        if (n == 1) {
            return 1;
        }
        if (dp[n] == -1) {
            dp[n] = n;
            for (ll i = 1;i <= n / 2;++i) {
                dp[n] = max(dp[n], i * func(n - i));
            }
        }
        return dp[n];
    }
    ll integerBreak(ll n) {
        dp.resize(n + 1, -1);
        ll ans = -1;
        for (ll i = 1;i <= n / 2;++i) {
            ans = max(ans, i * func(n - i));
        }
        return ans;
    }
};