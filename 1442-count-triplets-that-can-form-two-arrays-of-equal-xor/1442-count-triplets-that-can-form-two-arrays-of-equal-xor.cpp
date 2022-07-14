class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int countTriplets(vector<int>& v) {
        ll sz = v.size(), res = 0;
        for (ll i = 1;i < sz;++i)
            v[i] ^= v[i - 1];
        for (ll i = 0;i < sz;++i) {
            for (ll j = i + 1;j < sz;++j) {
                for (ll k = j;k < sz;++k) {
                    ll a = v[j - 1];
                    if (i)
                        a ^= v[i - 1];
                    ll b = v[k] ^ v[j - 1];
                    if (a == b)
                        ++res;
                }
            }
        }
        return res;
    }
};