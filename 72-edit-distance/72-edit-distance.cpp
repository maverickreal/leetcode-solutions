class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll szs, szt;
    vi(vi(ll))dp;
    ll func(const string& s, const string& t, ll is, ll it) {
        if (it == szt) {
            return szs - is;
        }
        if (is == szs) {
            return szt - it;
        }
        if (dp[is][it] == -1) {
            if (s[is] == t[it]) {
                dp[is][it] = func(s, t, is + 1, it + 1);
            }
            else {
                dp[is][it] = 1 + min({ func(s, t, is + 1, it + 1), func(s, t, is, it + 1), func(s, t, is + 1, it) });
            }
        }
        //cout << is << ' ' << it << ' ' << ans << nl;
        return dp[is][it];
    }
    int minDistance(const string& s, const string& t) {
        szs = s.length(), szt = t.length();
        dp.resize(szs, vi(ll)(szt, -1));
        return func(s, t, 0, 0);
    }
};