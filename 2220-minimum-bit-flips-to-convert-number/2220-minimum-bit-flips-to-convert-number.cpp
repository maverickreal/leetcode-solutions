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
    int minBitFlips(ll a, ll b) {
        ll res = 0;
        while (a || b) {
            res += (a & 1) ^ (b & 1);
            a >>= 1;
            b >>= 1;
        }
        return res;
    }
};