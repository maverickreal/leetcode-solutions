class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(ll)dp;
    ll func(vi(ll)& v, ll in) {
        ll sz = v.size();
        if (in >= sz)
            return 0;
        if (dp[in] == -1)
        dp[in] = max(func(v, in + 1), v[in]+func(v, in + 2));
        return dp[in];
    }
    int rob(vector<int>& v) {
        dp.resize(v.size(), -1);
        ll res = func(v, 1);
        dp.clear();
        dp.resize(v.size(), -1);
        v.pop_back();
        res = max(res, func(v, 0));
        // for(ll it:dp)
        //     cout<<it<<' ';
        // cout<<nl;
        return max(v[0], res);
    }
};