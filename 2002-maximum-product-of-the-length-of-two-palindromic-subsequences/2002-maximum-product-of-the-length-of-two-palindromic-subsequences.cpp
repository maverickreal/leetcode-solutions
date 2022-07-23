class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    ll palin(const string& s, ll bm) {
        if (!bm)
            return 0;
        ll ptr = -1;
        string tmp;
        while (bm) {
            ++ptr;
            if (bm & 1) {
                tmp.pb(s[ptr]);
            }
            bm >>= 1;
        }
        ll sz = tmp.length();
        for (ll i = 0;i < sz / 2;++i) {
            if (tmp[i] != tmp[sz - 1 - i])
                return 0;
        }
        return tmp.length();
    }
public:
    int maxProduct(string& s) {
        ll sz = s.length(), res = 0;
        vi(pi)v;
        for (ll i = 0;i < (1 << sz);++i) {
            ll sza = palin(s, i);
            if (!sza) {
                continue;
            }
            for (pi p : v) {
                if (!(p.first & i)) {
                    res = max(res, p.second * sza);
                }
            }
            v.pb({ i, sza });
        }
        return res;
    }
};