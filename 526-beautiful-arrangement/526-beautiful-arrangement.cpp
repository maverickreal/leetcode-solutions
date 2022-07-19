class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    ll res = 0;
    void func(ll pos, ll used, const ll& n) {
        if (pos == n + 1) {
            ++res;
            return;
        }
        for (ll i = 1;i <= n;++i) {
            if (!((pos % i && i % pos) || (used & (1ll << i)))) {
                func(pos + 1, used | (1ll << i), n);
            }
        }
    }
    int countArrangement(int n) {
        func(1, 0, n);
        return res;
    }
};