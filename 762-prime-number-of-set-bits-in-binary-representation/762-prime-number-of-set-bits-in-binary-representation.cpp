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
    int countPrimeSetBits(int left, int right) {
        ll res = 0;
        for (ll i = left;i <= right;++i) {
            ll j = i, o = 0;
            while (j) {
                o += j & 1;
                j >>= 1;
            }
            if (o == 2 || o == 3 || o == 5 || o == 7 || o == 11 || o == 13 || o == 17 || o == 19 || o == 23 || o == 29 || o == 31)
                ++res;
        }
        return res;
    }
};