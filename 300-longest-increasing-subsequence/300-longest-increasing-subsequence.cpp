class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    vi(ll)dp;
    ll func(vi(int)& v, ll in, ll pre) {
        if (in == sz) {
            return 0;
        }
        ll res = func(v, in + 1, pre);
        if (v[in] <= pre) {
            return res;
        }
        if (dp[in] == -1) {
            dp[in] = func(v, in + 1, v[in]) + 1;
        }
        return max(dp[in], res);
    }
    int lengthOfLIS(vi(int)& v) {
        sz = v.size();
        dp.resize(sz, -1);
        return func(v, 0, LLONG_MIN);
    }
};