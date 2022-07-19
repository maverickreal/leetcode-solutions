class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    bool disjoint(ll a, ll b) {
        while (a && b) {
            if ((a & 1) && (b & 1))
                return false;
            a >>= 1;
            b >>= 1;
        }
        return true;
    }
    int maxProduct(vector<string>& v) {
        ll sz = v.size();
        vi(ll)masks(sz);
        for (ll i = 0;i < sz;++i) {
            ll& mask = masks[i];
            for (const char& ch : v[i]) {
                mask |= (1 << (ch - 'a'));
            }
        }
        ll res = 0;
        for (ll i = 0;i < sz;++i) {
            for (ll j = i + 1;j < sz;++j) {
                if (disjoint(masks[i], masks[j])) {
                    res = max(res, ll(v[i].length() * v[j].length()));
                }
            }
        }
        // for(ll it:masks)
        //     cout<<it<<' ';
        return res;
    }
};