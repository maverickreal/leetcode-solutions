class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    ll mod = 1e9 + 7;
    char nl = '\n';
public:
    ll sz;
    vi(ll)dp;
    ll func(vi(ll)& v, ll in) {
        if (in >= sz)
            return 0;
        if (dp[in] > 10000)
            dp[in] = max(v[in], v[in] + func(v, in + 1));
        return dp[in];
    }
    int maxSubArray(vector<int>& v) {
        sz = v.size();
        dp.resize(sz, 10001);
        func(v, 0);
        return *max_element(dp.begin(), dp.end());
    }
};