class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    vi(vi(int))dp;
    vi(int) func(const vi(int)& v, ll in) {
        if (in >= sz) {
            return {};
        }
        if (dp[in].empty()) {
            dp[in] = { v[in] };
            for (ll i = in + 1;i < sz;++i) {
                if (v[i] % v[in] == 0) {
                    vi(int)rec = func(v, i);
                    rec.pb(v[in]);
                    if (rec.size() > dp[in].size()) {
                        dp[in] = rec;
                    }
                }
            }
        }
        return dp[in];
    }
    vector<int> largestDivisibleSubset(vector<int>& v) {
        sz = v.size();
        dp.resize(sz, {});
        sort(v.begin(), v.end());
        for (ll i = sz - 1;i > -1;--i) {
            func(v, i);
        }
        ll ansIn = 0;
        for (ll i = 1;i < sz;++i) {
            if (dp[i].size() > dp[ansIn].size()) {
                ansIn = i;
            }
        }
        return dp[ansIn];
    }
};