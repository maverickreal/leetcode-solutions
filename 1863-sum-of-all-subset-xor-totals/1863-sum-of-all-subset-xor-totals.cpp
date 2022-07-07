class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int subsetXORSum(vector<int>& v) {
        ll sz = v.size();
        vi(ll)xo = { 0, v[0] };
        for (ll i = 1;i < sz;++i) {
            ll szx = xo.size();
            for (ll j = 0;j < szx;++j)
                xo.pb(xo[j] ^ v[i]);
        }
        return accumulate(xo.begin(), xo.end(), 0);
    }
};