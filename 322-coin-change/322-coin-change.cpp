class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    vi(vi(ll))dp;
    ll func(const vi(int)& v, ll in, ll n) {
        if (n == 0) {
            return 0;
        }
        if (in == sz || n < 0) {
            return LLONG_MAX;
        }
        if (dp[in][n] == -1) {
            dp[in][n] = func(v, in + 1, n);
            if (v[in] <= n) {
                ll rec = func(v, in, n - v[in]);
                if (rec < LLONG_MAX) {
                    dp[in][n] = min(dp[in][n], rec + 1);
                }
            }
        }
        return dp[in][n];
    }
    int coinChange(const vi(int)& v, ll n) {
        sz = v.size();
        dp.resize(sz, vi(ll)(n + 1, -1));
        return func(v, 0, n);
    }
};