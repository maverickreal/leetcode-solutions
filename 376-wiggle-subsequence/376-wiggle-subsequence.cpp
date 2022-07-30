class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    vi(pi)dp;
    ll func(vi(int)& v, ll in, ll pre, bool inc) {
        if (in == sz) {
            return 0;
        }
        ll ans = func(v, in + 1, pre, inc);
        if (pre != -1 && ((inc && v[in] <= v[pre]) || (!inc && v[in] >= v[pre]))) {
            return ans;
        }
        if (dp[in] == pi(-1, -1)) {
            dp[in].first = 1 + func(v, in + 1, in, true);
            dp[in].second = 1 + func(v, in + 1, in, false);
        }
        return max(ans, inc ? dp[in].second : dp[in].first);
    }

    int wiggleMaxLength(vector<int>& v) {
        sz = v.size();
        dp.resize(sz, { -1,-1 });
        func(v, 0, -1, true);
        ll res=0;
        for(pi p:dp){
            res=max(res, max(p.first, p.second));
        }
        return res;
    }
};