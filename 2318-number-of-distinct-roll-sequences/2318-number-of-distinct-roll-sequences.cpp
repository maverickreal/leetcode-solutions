class Solution {
public:
    typedef long long ll;
    typedef long double ld;
#define vi(x) vector<x>
    typedef pair<ll, vi(ll)> pi;
#define li(x) list<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';

    ll sum(const vi(ll)& v, ll j) {
        ll res = 0;
        for (ll i = 0;i < v.size();++i)
            if (i != j)
                res = (res + v[i]) % mod;
        return res;
    }

    int distinctSequences(ll n) {
        if (n == 1)
            return 6;
        vi(vi(ll))dp(6);
        dp[0] = { 0,1,1,1,1,1 };
        dp[1] = { 1,0,1,0,1,0 };
        dp[2] = { 1,1,0,1,1,0 };
        dp[3] = { 1,0,1,0,1,0 };
        dp[4] = { 1,1,1,1,0,1 };
        dp[5] = { 1,0,0,0,1,0 };
        for (ll i = 3;i <= n;++i) {
            vi(vi(ll))tmp(6, vi(ll)(6));
            for (ll j = 0;j < 6;++j) {
                for (ll k = 0;k < 6;++k)
                    if (j != k && gcd(j + 1, k + 1) == 1)
                        tmp[j][k] = sum(dp[k], j);
            }
            dp = tmp;
        }
        ll ans = 0;
        for (const vi(ll)& it : dp)
            for (const ll& ti : it)
                ans = (ans + ti) % mod;
        return ans;
    }
};