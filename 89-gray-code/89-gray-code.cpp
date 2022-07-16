class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vector<int> grayCode(int n) {
        vi(ll)res = { 0, 1 };
        for (ll i = 2;i <= n;++i) {
            ll it = (1 << (i - 1));
            for (ll j = res.size() - 1;j > -1;--j) {
                res.pb(it ^ res[j]);
            }
        }
        return res;
    }
};