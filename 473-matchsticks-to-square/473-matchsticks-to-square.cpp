class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz, bm, tot;
    vi(vi(ll))dp;
    bool func(const vi(int)& v, ll k, ll len) {
        if (k == 4) {
            return true;
        }
        if (len == tot / 4) {
            return func(v, k + 1, 0);
        }
        if (dp[k][bm] == -1) {
            dp[k][bm] = 0;
            for (ll i = 0;i < sz && len + v[i] <= tot / 4;++i) {
                if (bm & (1 << i)) {
                    continue;
                }
                bm |= (1 << i);
                if (func(v, k, len + v[i])) {
                    dp[k][bm] = 1;
                    break;
                }
                bm ^= (1 << i);
            }
        }
        return dp[k][bm];
    }
    bool makesquare(vector<int>& v) {
        sz = v.size(), bm = 0, tot = accumulate(v.begin(), v.end(), 0);
        if (tot % 4) {
            return false;
        }
        sort(v.begin(), v.end());
        dp.resize(4, vi(ll)(1 << 15, -1));
        return func(v, 0, 0);
    }
};