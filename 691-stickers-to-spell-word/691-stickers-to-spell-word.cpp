class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll n;
    unordered_map<string, ll>dp;
    vi(vi(ll))ump;
    ll func(const string& tar) {
        if (dp.find(tar) == dp.end()) {
            dp[tar] = LLONG_MAX;
            vi(ll)tarump(26);
            for (char ch : tar) {
                ++tarump[ch - 'a'];
            }
            for (ll in = 0;in < n;++in) {
                if (!ump[in][tar[0] - 'a']) {
                    continue;
                }
                string rem;
                for (ll i = 0;i < 26;++i) {
                    if (ump[in][i] < tarump[i]) {
                        rem.append(string(tarump[i] - ump[in][i], 'a' + i));
                    }
                }
                ll rec = func(rem);
                if (rec < LLONG_MAX) {
                    dp[tar] = min(dp[tar], rec + 1);
                }
            }
        }
        return dp[tar];
    }
    int minStickers(vector<string>& v, string& s) {
        n = v.size();
        ump.assign(n, vi(ll)(26));
        for (ll i = 0;i < n;++i) {
            for (char ch : v[i]) {
                ++ump[i][ch - 'a'];
            }
        }
        dp[""]=0;
        ll ans = func(s);
        return (ans == LLONG_MAX ? -1 : ans);
    }
};