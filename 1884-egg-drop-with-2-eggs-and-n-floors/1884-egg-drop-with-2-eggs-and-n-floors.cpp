class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(vi(ll))dp;
    ll func(ll n, ll rem) {
        if (n < 2 || rem < 2) {
            return n;
        }
        if (dp[n][rem] == -1) {
            dp[n][rem] = LLONG_MAX;
            for (ll i = 1;i <= n;++i) {
                dp[n][rem] = min(dp[n][rem], max(func(i - 1, rem - 1), func(n - i, rem)) + 1);
            }
        }
        return dp[n][rem];
    }
    int twoEggDrop(int n) {
        dp.resize(n + 1, vi(ll)(3, -1));
        return func(n, 2);
    }
};