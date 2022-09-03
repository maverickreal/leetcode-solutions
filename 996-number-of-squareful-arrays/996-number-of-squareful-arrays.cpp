class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    unordered_set<ll>ust;
    vi(vi(ll))dp;
    bool isps(const ll& n) {
        if (n < 4) {
            return (n < 2);
        }
        ll i = 1;
        for (;i * i < n;++i);
        return (i * i == n);
    }
    ll func(const vi(int)& v, ll bm, ll pre) {
        if (__builtin_popcount(bm) == sz) {
            return 1;
        }
        if (dp[bm][pre] == -1) {
            dp[bm][pre] = 0;
            for (ll i = 0;i < sz;++i) {
                if ((bm & (1 << i)) == 0 && (pre == sz || ust.find(v[pre] + v[i]) != ust.end()) && (i == 0 || v[i - 1] < v[i] || (bm & (1 << (i - 1))))) {
                    dp[bm][pre] += func(v, bm | (1 << i), i);
                }
            }
        }
        return dp[bm][pre];
    }
    int numSquarefulPerms(vector<int>& v) {
        sz = v.size();
        for (ll i = 0;i * i <= mod - 7;++i) {
            ust.insert(i * i);
        }
        sort(v.begin(), v.end());
        dp.assign(1 << sz, vi(ll)(sz + 1, -1));
        return func(v, 0, sz);
    }
};