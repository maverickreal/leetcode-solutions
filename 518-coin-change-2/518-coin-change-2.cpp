class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(vi(ll))dp;
    ll sz;
    ll func(const vi(int)& v, ll in, ll n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0 || sz == in) {
            return 0;
        }
        if (dp[in][n] == -1) {
            dp[in][n] = func(v, in + 1, n);
            if (v[in] <= n) {
                dp[in][n] += func(v, in, n - v[in]);
            }
        }
        return dp[in][n];
    }
    int change(ll n, vi(int)& v) {
        sz = v.size();
        dp.resize(sz, vi(ll)(n + 1, -1));
        return func(v, 0, n);
    }
};