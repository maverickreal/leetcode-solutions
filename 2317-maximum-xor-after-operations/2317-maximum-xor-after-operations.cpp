class Solution {
    typedef int ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define endl '\n'
    const ll mod = 1e9;
public:
    int maximumXOR(vector<int>& v) {
        ll res = 0, sz = v.size(), cnt = 0;
        while (true) {
            bool fl = false, zero = true;
            for (ll& it : v) {
                if (it & 1)
                    fl = true;
                it >>= 1;
                if (it)
                    zero = false;
            }
            if (fl)
                res += (1 << cnt);
            ++cnt;
            if (zero)
                break;
        }
        return res;
    }
};