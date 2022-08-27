class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    static bool cmp(const vi(int)& a, const vi(int)& b) {
        return (a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]);
    }
    ll sz;
    vi(vi(ll))dp;
    ll bs(const vi(vi(int))& v, ll l, ll x) {
        ll r = sz - 1, ans = sz;
        while (l <= r) {
            ll m = l + ((r - l) >> 1);
            if (v[m][0] > x) {
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
    ll func(const vi(vi(int))& v, ll in, ll rem) {
        if (in == sz || rem == 0) {
            return 0;
        }
        if (dp[in][rem] == -1) {
            dp[in][rem] = max(func(v, in + 1, rem), v[in][2] + func(v, bs(v, in + 1, v[in][1]), rem - 1));
        }
        return dp[in][rem];
    }
    int maxValue(vector<vector<int>>& v, int k) {
        sz = v.size();
        dp.resize(sz, vi(ll)(k + 1, -1));
        sort(v.begin(), v.end(), cmp);
        return func(v, 0, k);
    }
};