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
    ll func(const vi(int)& v, ll bm, const int& n, ll cur) {
        if (dp[bm][cur] == -1) {
            ll& res = dp[bm][cur];
            for (ll i = 0;i < sz;++i) {
                if (bm & (1 << i)) {
                    continue;
                }
                ll rem = cur, ans = 0;
                if (rem < v[i]) {
                    ++ans;
                    rem = n;
                }
                ans += func(v, bm | (1 << i), n, rem - v[i]);
                if (res == -1 || res > ans) {
                    res = ans;
                }
            }
            res = max(res, 0LL);
        }
        return dp[bm][cur];
    }
    int minSessions(vector<int>& v, int n) {
        sz = v.size();
        dp.resize(1 << 14, vi(ll)(16, -1));
        return func(v, 0, n, 0);
    }
};