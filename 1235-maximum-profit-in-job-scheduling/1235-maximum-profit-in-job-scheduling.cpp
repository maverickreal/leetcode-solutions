class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    static bool cmp(const vi(ll)& a, const vi(ll)& b) {
        return (a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]);
    }
    ll sz;
    vi(vi(ll))v;
    vi(ll)dp;
    ll bs(ll l, ll x) {
        ll r = sz - 1, ans = sz;
        while (l <= r) {
            ll m = l + ((r - l) >> 1);
            if (v[m][0] >= x) {
                ans = m, r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
    ll func(ll in) {
        if (in == sz) {
            return 0;
        }
        if (dp[in] == -1) {
            dp[in] = max(func(in + 1), v[in][2] + func(bs(in + 1, v[in][1])));
        }
        return dp[in];
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        sz = p.size();
        v.resize(sz, vi(ll)(3));
        for (ll i = 0;i < sz;++i) {
            v[i] = { s[i], e[i], p[i] };
        }
        sort(v.begin(), v.end(), cmp);
        dp.resize(sz, -1);
        return func(0);
    }
};