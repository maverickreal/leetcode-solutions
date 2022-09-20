class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    string bm;
    unordered_map<string, vi(ll)>dp;
    ll func(const vi(int)& v, ll in, const int& n) {
        if (in == sz) {
            return 0;
        }
        if (dp[bm].empty()) {
            dp[bm].assign(sz, -1);
        }
        ll& ans = dp[bm][in];
        if (ans == -1) {
            ans = 0;
            for (ll i = 0;i < n;++i) {
                if (bm[i] < '2') {
                    ++bm[i];
                    ans = max(ans, (v[in] & (i + 1)) + func(v, in + 1, n));
                    --bm[i];
                }
            }

        }
        return ans;
    }
    int maximumANDSum(vector<int>& v, int n) {
        sz = v.size();
        bm.assign(n, '0');
        return func(v, 0, n);
    }
};