class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz, res = 0;
    vi(vi(ll))dp;
    ll func(vi(ll)& v, ll in, ll ss, const ll& fee) {
        if (in > sz - 1 || (in == sz - 1 && ss))
            return 0;
        if (dp[in][ss] == -1) {
            dp[in][ss] = func(v, in + 1, ss, fee);
            if (ss) {
                dp[in][ss] = max(dp[in][ss], func(v, in + 1, false, fee) - v[in]);
                res = max(res, dp[in][ss]);
            }
            else {
                dp[in][ss] = max(dp[in][ss], v[in] - fee + func(v, in + 1, true, fee));
            }
        }
        return dp[in][ss];
    }
    int maxProfit(vector<int>& v, int fee) {
        sz = v.size();
        dp.resize(sz, { -1,-1 });
        func(v, 0, true, fee);
        return res;
    }
};