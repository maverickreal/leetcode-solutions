class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int arithmeticTriplets(vector<int>& v, int diff) {
        ll res = 0, sz = v.size();
        for (ll i = 0;i < sz;++i) {
            for (ll j = i + 1;j < sz;++j) {
                for (ll k = j + 1;k < sz;++k) {
                    if (v[j] - v[i] == diff && v[k] - v[j] == diff) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};