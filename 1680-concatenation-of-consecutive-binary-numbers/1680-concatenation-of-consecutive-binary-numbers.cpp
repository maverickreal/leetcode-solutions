class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    public:
    int concatenatedBinary(int n) {
        ll ans = 1;
        for (ll i = 2;i <= n;++i) {
            ll sz = 0, j = i;
            while (j) {
                ++sz;
                j >>= 1;
            }
            ans = ((ans << sz) + i) % mod;
        }
        return ans;
    }
};