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
    static bool cmp(const vi(int)& a, const vi(int)& b) {
        return (a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]);
    }
    ll func(const vi(vi(int))& v, ll in) {
        if (in >= sz) {
            return 0;
        }
        if (dp[in] == -1) {
            dp[in] = 1;
            for (ll i = in + 1;i < sz;++i) {
                if (v[i][0] > v[in][1]) {
                    dp[in] = max(dp[in], 1 + func(v, i));
                }
            }
        }
        return dp[in];
    }
    int findLongestChain(vector<vector<int>>& v) {
        sz = v.size();
        sort(v.begin(), v.end(), cmp);
        dp.resize(sz, -1);
        for (ll i = sz - 1;i > -1;--i) {
            func(v, i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};