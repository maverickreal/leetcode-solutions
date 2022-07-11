class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    vi(ll)dp;
    ll func(vi(ll)& v, ll in) {
        if (in >= sz)
            return 0;
        if (dp[in] == -1)
            dp[in] = max(func(v, in + 1), (in*v[in]) + func(v, in + 2));
        return dp[in];
    }
    int deleteAndEarn(vector<int>& nums) {
        sz = 10002;
        dp.resize(sz, -1);
        vi(ll)v(sz);
        for (ll it : nums)
            ++v[it];
        return func(v, 0);
    }
};