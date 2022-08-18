class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(vi(ll))dp;
    ll m, n;
    vi(vi(bool))vis;
    ll func(const vi(int)& a, const vi(int)& b, ll ina, ll inb, ll prex, ll prey) {
        if (ina >= m || inb >= n) {
            return 0;
        }
        if (dp[ina][inb] == -1) {
            dp[ina][inb] = max(func(a, b, ina, inb + 1, prex, prey), func(a, b, ina + 1, inb, prex, prey));
        }
        ll ans = dp[ina][inb];
        if (a[ina] == b[inb] && ina > prex && inb > prey) {
            vis[0][ina] = true;
            vis[1][inb] = true;
            ans = max(ans, func(a, b, ina + 1, inb + 1, ina, inb) + 1);
            vis[0][ina] = false;
            vis[1][inb] = false;
        }
        return ans;
    }
    int maxUncrossedLines(vi(int)& a, vi(int)& b) {
        m = a.size(), n = b.size();
        vis.pb(vi(bool)(m));
        vis.pb(vi(bool)(n));
        dp.resize(m, vi(ll)(n, -1));
        return func(a, b, 0, 0, -1, -1);
    }
};