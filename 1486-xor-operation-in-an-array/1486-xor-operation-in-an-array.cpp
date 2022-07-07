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
    int xorOperation(int n, int start) {
        ll res = 0;
        for (ll i = 0;i < n;++i)
            res ^= start + (i << 1);
        return res;
    }
};